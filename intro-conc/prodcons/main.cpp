#include "colamsj.h"
#include "productor.h"
#include "consumidor.h"

#include <thread>
#include <vector>

int main() {
  cola_mensajes cm;

  std::vector<productor> vp;
  for (int i=0; i<10; ++i) {
    vp.emplace_back(i,cm);
  }
  std::vector<consumidor> vc;
  for (int i=0; i<4; ++i) {
    vc.emplace_back(cm);
  }

  std::vector<std::thread> vt;
  for (auto && x : vp) {
    vt.emplace_back(std::move(x));
  }
  for (auto && x : vc) {
    vt.emplace_back(std::move(x));
  }

  std::this_thread::sleep_for(std::chrono::seconds(5));
  cm.avisa_fin();

  std::cout << "** AVISO DE FIN ***" << std::endl;

  for (auto && t : vt) {
    t.join();
  }

  return 0;
}
