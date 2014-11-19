#include <chrono>
#include <thread>
#include <future>
#include <random>
#include <iostream>

double f(int s, int n) {
  using namespace std;

  default_random_engine engine(s);
  normal_distribution<double> gen(1.0, 0.25);
 
  double r = 0.0;
  for (int i=0; i<n; ++i) {
    r += gen(engine);
  }
  
  return r/n;
}

int main() {
  using namespace std;

  auto r1 = async(launch::async,f, 3, 1000000);
  auto r2 = async(launch::async,f, 115, 2500000);

  cout << r1.get() << endl;
  cout << r2.get() << endl;

  return 0;
}
