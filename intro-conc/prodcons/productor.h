#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "generador.h"
#include "colamsj.h"

class productor {
public:
  productor(int id, cola_mensajes & c) : ident{id}, cola{c} {}

  void operator()();

private:
  int ident;
  generador gen;
  cola_mensajes & cola;
};

#endif
