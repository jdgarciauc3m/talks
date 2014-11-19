#include "consumidor.h"
#include <iostream>
#include <thread>

void consumidor::operator()() {
  while (!cola.fin_produccion()) {
    mensaje m;
    cola.obten(m);
    std::cout << "Recibido mensaje " << m << std::endl;
  }
  while (cola.num_productores() > 0) {
    mensaje m;
    if (cola.intenta_obtener(m)) {
      std::cout << "Recibido mensaje " << m << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(0));
  }
}


