#include <chrono>
#include <thread>
#include <future>
#include <iostream>
#include "tasks.h"

int main() {
  using namespace std;

  auto r1 = async(launch::async,f);
  auto r2 = async(launch::async,g);

  r1.get();
  r2.get();

  return 0;
}
