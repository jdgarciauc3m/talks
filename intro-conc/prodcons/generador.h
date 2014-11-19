#ifndef GENERADOR_H
#define GENERADOR_H

#include "mensaje.h"
#include <random>

class generador {
public:
  generador() = default;

  generador(generador && g);

  mensaje operator()(int id);

private:
  std::random_device rgen;
  std::uniform_int_distribution<int> dist_espera{1, 1000};
  int sig = 0;
};

#endif
