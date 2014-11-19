#include <iostream>
#include <thread>

int x = 42;

void f() { ++x; }
void g() { x=0; }
void h() { std::cout << "Hola" << std::endl; }
void i() { std::cout << "Adios" << std::endl; }

void carrera() {
  using namespace std;
  thread t1{f}; thread t2{g};
  t1.join(); t2.join();

  thread t3{h}; thread t4{i};
  t3.join(); t4.join();
}

int main() {
  carrera();
  return 0;
}
