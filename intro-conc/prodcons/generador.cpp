#include "generador.h"
#include <chrono>
#include <thread>

generador::generador(generador && g) :
  rgen{}, 
  dist_espera{std::move(g.dist_espera)}, 
  sig{sig}
{
}

mensaje generador::operator()(int id) {
  using namespace std::this_thread;
  using namespace std::chrono;

  auto espera = milliseconds(dist_espera(rgen));
  sleep_for(espera);
  sig++;
  return { id, sig, "mensaje " + std::to_string(sig) };
}

