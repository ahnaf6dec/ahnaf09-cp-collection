#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using clk = chrono::high_resolution_clock;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd_ll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

int rnd_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

double rnd_double(double l, double r) {
  return uniform_real_distribution<double>(l, r)(rng);
}

// tastcase maker
namespace data {

// declare variable

void generate() {
  // generate date & stroe to the variable

}

void print() {
  // print generated testcases
}
}  // namespace data

/* SOLUTIONS */
ll brute() {
  // slow but correct implementation
}

ll fast() {
  // optimized implementation
}

// timer for check tle or not
template <typename F>
double measure_time(F &&func) {
  auto start = clk::now();
  func();
  auto end = clk::now();
  return chrono::duration<double, milli>(end - start).count();
}



int main() {
  const double TIME_LIMIT_MS = 5.0;

  for (long long iter = 1;; ++iter) {
    data::generate();

    ll ans_brute, ans_fast;
    double t_brute = measure_time([&] { ans_brute = brute(); });
    double t_fast = measure_time([&] { ans_fast = fast(); });

    if (ans_brute != ans_fast) {
      cout << "WRONG ANSWER DETECTED\n";
      data::print();
      cout << "Brute answer: " << ans_brute << "\n";
      cout << "Fast answer : " << ans_fast << "\n";
      return 0;
    }

    if (t_fast > TIME_LIMIT_MS) {
      cout << "TIME LIMIT EXCEEDED\n";
      data::print();
      cout << "Fast execution time: " << t_fast << " ms\n";
      return 0;
    }

    if (iter % 1000 == 0) {
      cout << "Passed " << iter << " tests | Fast time: " << t_fast << " ms\n";
    }
  }
  return 0;
}
