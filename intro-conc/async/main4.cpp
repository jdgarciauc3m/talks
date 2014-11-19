#include <chrono>
#include <thread>
#include <future>
#include <random>
#include <iostream>

class mi_error {};

double f(int n) {
  if (n==0) throw mi_error{};
  else return 1000.0/n;
}

int main() {
  using namespace std;

  auto r1 = async(launch::async,f, 0);

  try {
    cout << r1.get() << endl;
  }
  catch (const mi_error &) {
    cerr << "Error" << endl;
  }

  return 0;
}
