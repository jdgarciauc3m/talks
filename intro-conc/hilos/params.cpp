#include <thread>

void f1(int x);

struct f2 {
  void operator()();
  f2(int px) : x{px} {}
  int x;
};

void g() {
  using namespace std;
  thread t1{f1, 10}; // Ejecuta f1(10)
  thread t2{f2{20}}; // Ejecuta f2{20}.operator()()
  thread t3{[] { f1(42); } }; // Ejecuta una lambda

  t1.join();
  t2.join();
  t3.join();
}

void f1(int x) {};

void f2::operator()() {
 x++;
}

int main() {
  g();
}
