#include <thread>
#include <vector>

void f(int i);

void g() {
  std::vector<std::thread> vt;
  for (int i=0; i< 8; ++i) {
    vt.push_back(std::thread(f,i));
  }

  for (auto & t : vt) { // Espera a que todos los hilos terminen
    t.join();
  }
}

int main() {
  g();
  return 0;
}

#include <iostream>

void f(int i) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << i << std::endl;
}

