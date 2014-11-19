#ifndef COLA_MENSAJES_H
#define COLA_MENSAJES_H

#include "mensaje.h"

#include <atomic>
#include <mutex>
#include <condition_variable>
#include <list>

class cola_mensajes {
public:
  void pon(const mensaje & m); 
  void obten(mensaje & m);
  bool intenta_obtener(mensaje & m);
  bool esta_vacia() const;

  void registra_productor() { nproductores++; }
  void olvida_productor() { nproductores--; }
  int num_productores() const { return nproductores; }

  void avisa_fin() { fin = true; }
  bool fin_produccion() const { return fin; }

private:
public:
  std::list<mensaje> cola;
  mutable std::mutex cola_mutex;
  mutable std::condition_variable puesto;
  std::atomic<int> nproductores {0};
  std::atomic<bool> fin{false};
};

#endif
