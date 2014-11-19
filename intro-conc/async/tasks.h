void f() {
  using namespace std;
  constexpr int max = 10;
  for (int i=0; i<max; ++i) {
    this_thread::sleep_for(chrono::milliseconds(5));
    cout.put('+').flush();
  }
}

void g() {
  using namespace std;
  constexpr int max = 20;
  for (int i=0; i<max; ++i)  {
    std::this_thread::sleep_for(chrono::milliseconds(5));
    cout.put('*').flush();
  }
}
