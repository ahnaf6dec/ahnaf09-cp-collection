#pragma once
#include <bits/stdc++.h>
using namespace std;

void fileIO(void){
  freopen("in.txt", "r", stdin);    // Redirects cin
  freopen("out.txt", "w", stdout);  // Redirects cout
  freopen("err.txt", "w", stderr);   // Redirects cerr
}


namespace IOUtil {

// -------- CONFIGURATION & MACROS --------
#ifndef sz
#define sz(x) ((int)(x).size())
#endif

// Helper type trait to detect standard vector types at compile time
template <typename T>
struct is_vector : false_type {};
template <typename T, typename A>
struct is_vector<vector<T, A>> : true_type {};
template <typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

// -----------------------------------------------------------------------------
// 1. ADVANCED VARIADIC INPUT ENGINE (`read`)
// -----------------------------------------------------------------------------

// Base overloads for distinct structural types
template <typename T1, typename T2>
inline void read_single(pair<T1, T2> &p) {
  cin >> p.first >> p.second;
}

template <typename T>
inline void read_single(vector<T> &v) {
  for (auto &x : v) {
    if constexpr (is_vector_v<T>) {  // Matrix / 2D Vector case
      for (auto &y : x) cin >> y;
    } else {  // 1D Vector case
      cin >> x;
    }
  }
}

template <typename T>
inline void read_single(T &x) {
  cin >> x;
}

/* Use Case: Read any mixed combination of variables, arrays, and matrices
   seamlessly. Example: read(n, vector_a, matrix_b, target_integer); */
template <typename... Args>
inline void read(Args &...args) {
  (read_single(args),
   ...);  // C++17 Fold Expression for processing elements in order
}

// -----------------------------------------------------------------------------
// 2. ADVANCED VARIADIC OUTPUT ENGINE (`print` / `print2D` / `printTuple`)
// -----------------------------------------------------------------------------

// Forward declarations to allow seamless structural nested resolution
template <typename T>
inline void print_single(const vector<T> &v, char sep = ' ');
template <typename T1, typename T2>
inline void print_single(const pair<T1, T2> &p);
template <typename... T>
inline void printTuple(const tuple<T...> &t);

template <typename T>
inline void print_single(const T &x) {
  cout << x;
}

template <typename T1, typename T2>
inline void print_single(const pair<T1, T2> &p) {
  cout << p.first << " " << p.second;
}

template <typename T>
inline void print_single(const vector<T> &v, char sep) {
  for (int i = 0; i < sz(v); i++) {
    if constexpr (is_vector_v<T>) {  // Handle 2D vector layouts inline cleanly
      print_single(v[i], sep);
    } else {
      cout << v[i] << (i + 1 < sz(v) ? sep : "");
    }
  }
}

/* Use Case: Prints mixed parameters separated by spaces, finishing with a
   newline character. Example: print("Answer is:", ans_scalar, vector_res); */
template <typename T, typename... Args>
inline void print(const T &first, const Args &...rest) {
  print_single(first, ' ');
  if constexpr (sizeof...(rest) > 0) {
    cout << " ";
    print(rest...);
  } else {
    cout << "\n";
  }
}

/* Use Case: Printing a multi-dimensional matrix with a custom element spacing
 * setup. */
template <typename T>
inline void print2D(const vector<vector<T>> &m, char sep = ' ') {
  for (const auto &row : m) {
    print_single(row, sep);
    cout << "\n";
  }
}

/* Use Case: For unpacking and printing coordinate pairs, ranges, or custom
 * tuple objects. */
template <typename... T>
inline void printTuple(const tuple<T...> &t) {
  apply(
      [](auto &&...args) {
        size_t i = 0;
        ((cout << args << (++i < sizeof...(args) ? ", " : "")), ...);
      },
      t);
  cout << "\n";
}

}  // namespace IOUtil

// -----------------------------------------------------------------------------
// DEMO / MAIN EXECUTABLE BOILERPLATE
// -----------------------------------------------------------------------------
using namespace IOUtil;

int main() {
  // Optimizing Standard I/O operations
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  /* --- Usage Verification Example ---
  int n, r;
  read(n, r); // Read single scalars

  vector<int> vec(n);
  vector<vector<int>> mat(2, vector<int>(3));

  read(vec, mat); // Mixed type reading (1D vector + 2D matrix)

  print("--- Output Results ---");
  print("N:", n, "| R:", r);
  print("Vector elements:", vec);
  print("Matrix representation:");
  print2D(mat);
  */

  return 0;
}