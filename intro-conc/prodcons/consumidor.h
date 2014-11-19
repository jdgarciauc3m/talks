#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include "colamsj.h"
#include <iostream>

class consumidor {
public:
  consumidor(cola_mensajes & c) : cola{c} {}

  void operator()();

private:
  cola_mensajes & cola;
};


#endif
