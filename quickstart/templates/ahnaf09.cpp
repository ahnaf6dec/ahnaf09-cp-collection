/*
  In the name of Allah..
      _       _                     __   ___
  __ _| |__   | |__    _ __    ___  / _| / _ \
 / _` | '_ \  | '_ \  | '_ \  / _ \| |_ | (_) |
| (_| | | | | | | | | | | | ||  __/|  _| \__, |
 \__,_|_| |_| |_| |_| |_| |_| \___||_|     /_/

        Author : ahnaf09
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define sz(x) (int)(x).size()

// Standard Output Printers
template <typename T>
void print(const vector<T>& v, char s = ' ') {
  for (int i = 0; i < sz(v); i++) cout << v[i] << (i + 1 < sz(v) ? s : '\n');
}
template <typename T>
void print2D(const vector<vector<T>>& m, char s = ' ') {
  for (auto& r : m) print(r, s);
}

#ifdef OFFLINE
// Randomization Generators
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rnd_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
ll rnd_ll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
string rnd_str(int n, string s = "abc") {
  string t;
  for (int i = 0; i < n; i++) t += s[rnd_int(0, sz(s) - 1)];
  return t;
}

// Multi-Variable Variadic Debugger (Handles 1 to 10+ arguments dynamically)
template <typename... T>
void dbg_out(T... args) {
  size_t i = 0;
  ((cerr << args << (++i < sizeof...(args) ? ", " : "")), ...);
  cerr << endl;
}
#define dbg(...)                                                              \
  cerr << __FILE__ << " line " << __LINE__ << " [" << #__VA_ARGS__ << "] = ", \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif

void Solve() {
  // code
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
#ifdef OFFLINE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  clock_t st = clock();
#endif
  int T = 1;  
  // cin >> T;
  for (int tc = 1; tc <= T; tc++) {
#ifdef OFFLINE
    cout << "Case #" << tc << ": ";
#endif
    Solve();
  }
#ifdef OFFLINE
  cerr << "Time: " << fixed << setprecision(3)
       << (double)(clock() - st) * 1000 / CLOCKS_PER_SEC << " ms\n";
#endif
  return 0;
}
