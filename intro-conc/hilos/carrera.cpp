#include <iostream>
#include <thread>

int x = 42;

void f() { ++x; }
void g() { x=0; }

void carrera() {
  using namespace std;
  thread t1{f}; thread t2{g};
  t1.join(); t2.join();
}

int main() {
  carrera();
  return 0;
}
