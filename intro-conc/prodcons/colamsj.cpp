#include "colamsj.h"

void cola_mensajes::pon(const mensaje & m) {
  using namespace std;
  lock_guard<mutex> l{cola_mutex};
  cola.push_back(m);
  puesto.notify_one();
}

void cola_mensajes::obten(mensaje & m) {
  using namespace std;
  unique_lock<mutex> l{cola_mutex};
  puesto.wait(l, [this]{ return !cola.empty(); });
  m = cola.front();
  cola.pop_front();
}

bool cola_mensajes::intenta_obtener(mensaje & m) {
  using namespace std;
  unique_lock<mutex> l{cola_mutex};
  if (cola.empty()) return false;
  puesto.wait(l, [this]{ return !cola.empty(); });
  m = cola.front();
  cola.pop_front();
  return true;
}

bool cola_mensajes::esta_vacia() const {
  using namespace std;
  lock_guard<mutex> l{cola_mutex};
  return cola.empty();
}

