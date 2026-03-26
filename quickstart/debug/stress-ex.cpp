/*
    Professional Stress Testing Template example
    ------------------------------------
    Usage:
    - Set MODE = 1 / 2 / 3
    - Implement brute() and fast()
    - Run locally
    - NEVER submit this file

    MODE 1: Array (Second Maximum)
    MODE 2: Subarray (Maximum Subarray Sum)
    MODE 3: Math (GCD of Array)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using clk = chrono::high_resolution_clock;

/* ================= RNG (USER PROVIDED) ================= */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd_ll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

int rnd_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

double rnd_double(double l, double r) {
  return uniform_real_distribution<double>(l, r)(rng);
}

/* ================= CONFIG ================= */
#define MODE 1  // change: 1 / 2 / 3
const double TIME_LIMIT_MS = 5.0;

/* ================= TEST DATA ================= */
int n;
vector<int> a;

void generate() {
#if MODE == 1
  // Array: second maximum
  n = rnd_int(2, 10);
  a.resize(n);
  for (int &x : a) x = rnd_int(-100, 100);

#elif MODE == 2
  // Subarray: max subarray sum
  n = rnd_int(1, 20);
  a.resize(n);
  for (int &x : a) x = rnd_int(-10, 10);

#elif MODE == 3
  // Math: GCD of array
  n = rnd_int(1, 10);
  a.resize(n);
  for (int &x : a) x = rnd_int(1, 100);
#endif
}

void print_data() {
  cout << "n = " << n << "\n";
  cout << "a = ";
  for (int x : a) cout << x << " ";
  cout << "\n";
}

/* ================= BRUTE ================= */
ll brute() {
#if MODE == 1
  vector<int> b = a;
  sort(b.begin(), b.end());
  return b[n - 2];

#elif MODE == 2
  ll best = LLONG_MIN;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      ll sum = 0;
      for (int k = i; k <= j; k++) sum += a[k];
      best = max(best, sum);
    }
  return best;

#elif MODE == 3
  ll g = a[0];
  for (int i = 1; i < n; i++) g = gcd(g, (ll)a[i]);
  return g;
#endif
}

/* ================= FAST ================= */
ll fast() {
#if MODE == 1
  int mx1 = INT_MIN, mx2 = INT_MIN;
  for (int x : a) {
    if (x > mx1) {
      mx2 = mx1;
      mx1 = x;
    } else if (x > mx2) {
      mx2 = x;
    }
  }
  return mx2;

#elif MODE == 2
  ll best = a[0], cur = 0;
  for (int x : a) {
    cur = max((ll)x, cur + x);
    best = max(best, cur);
  }
  return best;

#elif MODE == 3
  ll g = 0;
  for (int x : a) g = gcd(g, (ll)x);
  return g;
#endif
}

/* ================= TIMER ================= */
template <typename F>
double measure(F &&f) {
  auto st = clk::now();
  f();
  auto en = clk::now();
  return chrono::duration<double, milli>(en - st).count();
}

/* ================= MAIN ================= */
int main() {
  for (ll iter = 1;; iter++) {
    generate();

    ll ans_brute, ans_fast;
    double t_fast;

    ans_brute = brute();
    t_fast = measure([&]() { ans_fast = fast(); });

    if (ans_brute != ans_fast) {
      cout << "WRONG ANSWER FOUND\n";
      print_data();
      cout << "Brute = " << ans_brute << "\n";
      cout << "Fast  = " << ans_fast << "\n";
      return 0;
    }

    if (t_fast > TIME_LIMIT_MS) {
      cout << "TIME LIMIT EXCEEDED\n";
      print_data();
      cout << "Fast time = " << t_fast << " ms\n";
      return 0;
    }

    if (iter % 1000 == 0) {
      cout << "Passed " << iter << " tests | Fast time: " << t_fast << " ms\n";
    }
  }

  return;
}
