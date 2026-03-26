#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

// the below versions are very classic and useful
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename... Args>
void read(T &f, Args &...r) {
  cin >> f;
  read(r...);
}
template <typename T>
void read(vector<T> &v) {
  for (auto &x : v) cin >> x;
}
template <typename T>
void read(vector<vector<T>> &m) {
  for (auto &r : m) read(r);
}
template <typename T>
void print(const T &x) {
  cout << x << "\n";
}
template <typename T, typename... Args>
void print(const T &f, const Args &...r) {
  cout << f << " ";
  print(r...);
}
template <typename T>
void print(const vector<T> &v, char sep = ' ') {
  for (int i = 0; i < sz(v); i++) cout << v[i] << (i + 1 < sz(v) ? sep : '\n');
}
template <typename T1, typename T2>
void print(const pair<T1, T2> &p) {
  cout << p.first << " " << p.second << "\n";
}
template <typename... T>
void printTuple(const tuple<T...> &t) {
  apply(
      [](auto &&...args) {
        size_t i = 0;
        ((cout << args << (++i < sizeof...(args) ? ", " : "")), ...);
      },
      t);
  cout << "\n";
}
template <typename T>
void print2D(const vector<vector<T>> &m, char sep = ' ') {
  for (auto &r : m) print(r, sep);
}

// more harder version of io
// Base case: single value
template <typename T>
void rd(T &x) {
  cin >> x;
}

// Multiple values (any combination of scalars and vectors)
template <typename T, typename... Args>
void rd(T &first, Args &...rest) {
  if constexpr (is_same_v<T, vector<typename T::value_type>>) {
    for (auto &v : first) cin >> v;
  } else {
    cin >> first;
  }
  if constexpr (sizeof...(rest) > 0) rd(rest...);
}

// ---------------- Output Templates ----------------

// Single value
template <typename T>
void print(const T &x) {
  cout << x << "\n";
}

// Multiple values
template <typename T, typename... Args>
void print(const T &first, const Args &...rest) {
  cout << first << " ";
  if constexpr (sizeof...(rest) > 0)
    print(rest...);
  else
    cout << "\n";
}

// Print vector
template <typename T>
void print(const vector<T> &v, char sep = ' ') {
  for (int i = 0; i < sz(v); i++) cout << v[i] << (i + 1 < sz(v) ? sep : '\n');
}

// Print pair
template <typename T1, typename T2>
void print(const pair<T1, T2> &p) {
  cout << p.first << " " << p.second << "\n";
}

// Print 2D vector
template <typename T>
void print2D(const vector<vector<T>> &m, char sep = ' ') {
  for (auto &row : m) print(row, sep);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;

  vector<int> vec(n);
  rd(vec, r);  // mixed input: vector + single int

  print("Vector:");
  print(vec);

  print("r:", r);

  // 2D vector example
  vector<vector<int>> mat(2, vector<int>(3));
  rd(mat);
  print("Matrix:");
  print2D(mat);

  return 0;
}
