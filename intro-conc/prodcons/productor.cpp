#include "productor.h"
#include <iostream>

void productor::operator()() {
  cola.registra_productor();
  while (!cola.fin_produccion()) {
    auto m = gen(ident);
    std::cout << "Generado mensaje " << m << std::endl;
    cola.pon(m);
  }
  cola.olvida_productor();
  std::cout << "Productor " << ident << " termina" << std::endl;
}

