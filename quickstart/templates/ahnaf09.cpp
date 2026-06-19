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
// standard vec printing
template <typename T>
void print(const vector<T>& v, char s = ' ') {
  for (int i = 0; i < sz(v); ++i) cout << v[i] << (i + 1 < sz(v) ? s : '\n');
  if (v.empty()) cout << endl;
}
template <typename T>
void print2D(const vector<vector<T>>& m, char s = ' ') {
  for (const auto& r : m) print(r, s);
}

#ifdef OFFLINE
// gen
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rnd_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
long long rnd_ll(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
string rnd_str(int n, string s = "abc") {
  string t;
  for (int i = 0; i < n; i++) t += s[rnd_int(0, (int)s.size() - 1)];
  return t;
}

#define debug(...)                                                          \
  cout << "[" << __FILE__ << ", line " << __LINE__ << "] [" << #__VA_ARGS__ \
       << "] = [",                                                          \
      _print(__VA_ARGS__)

void _print() { cout << "]\n"; }
template <typename T>
void __print(const T& x);
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T, size_t... Is>
void _print_tuple(const T& t, index_sequence<Is...>) {
  size_t f = 0;
  cout << '{';
  ((cout << (f++ ? ", " : ""), __print(get<Is>(t))), ...);
  cout << '}';
}
template <typename... T>
void __print(const tuple<T...>& t) {
  _print_tuple(t, index_sequence_for<T...>{});
}
template <typename T>
void __print(const T& x) {
  if constexpr (is_same_v<T, string> || is_same_v<T, char> ||
                is_pointer_v<decay_t<T>>) {
    cout << (is_same_v<T, char> ? "'" : "\"") << x
         << (is_same_v<T, char> ? "'" : "\"");
  } else if constexpr (is_same_v<T, bool>) {
    cout << (x ? "true" : "false");
  } else if constexpr (requires { x.has_value(); }) {
    if (x.has_value())
      __print(*x);
    else
      cout << "nullopt";
  } else if constexpr (requires { holds_alternative<int>(x); }) {
    visit([](const auto& arg) { __print(arg); }, x);
  } else if constexpr (requires {
                         x.begin();
                         x.end();
                       }) {
    int f = 0;
    cout << '{';
    for (auto& i : x) cout << (f++ ? ", " : ""), __print(i);
    cout << "}";
  } else {
    cout << x;
  }
}
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}

#else
#define debug(...)
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
