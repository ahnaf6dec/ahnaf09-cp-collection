#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// CONFIGURATION & MACROS
// -----------------------------------------------------------------------------
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;

const int MAX_SIEVE = 1e6;  // Adjust sizing for precomputations as needed

// -----------------------------------------------------------------------------
// HELPER UTILITIES
// -----------------------------------------------------------------------------
template <class T>
void print_vector(const vector<T>& v) {
  for (auto x : v) cout << x << ' ';
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 1. FACTOR & MULTIPLE UTILITIES (UPDATED)
// -----------------------------------------------------------------------------

// O(sqrt(N)) - Generates ALL sorted divisors/factors for any integer type
// (handles negatives)
template <class T>
auto get_divisors(T N) {
  using U = conditional_t<is_signed_v<T>, make_unsigned_t<T>, T>;
  U n = (N < 0 ? U(-N) : U(N));
  vector<U> lo, hi;
  for (U i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      lo.push_back(i);
      if (i != n / i) hi.push_back(n / i);
    }
  }
  lo.insert(lo.end(), hi.rbegin(), hi.rend());
  return lo;  // Returns sorted vector<U>
}

// O(sqrt(N)) - Generates the PRIME factorization of a number with
// counts/exponents Example: 12 -> {{2, 2}, {3, 1}} (since 12 = 2^2 * 3^1)
vector<pair<ll, int>> get_prime_factors(ll n) {
  vector<pair<ll, int>> factors;
  if (n < 2) return factors;

  // Check 2 and 3 explicitly for 6k +/- 1 optimization speed
  if (n % 2 == 0) {
    int cnt = 0;
    while (n % 2 == 0) {
      cnt++;
      n /= 2;
    }
    factors.push_back({2, cnt});
  }
  if (n % 3 == 0) {
    int cnt = 0;
    while (n % 3 == 0) {
      cnt++;
      n /= 3;
    }
    factors.push_back({3, cnt});
  }

  // Factor out elements up to sqrt(n)
  for (ll i = 5; i * i <= n; i += 6) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        cnt++;
        n /= i;
      }
      factors.push_back({i, cnt});
    }
    if (n % (i + 2) == 0) {
      int cnt = 0;
      while (n % (i + 2) == 0) {
        cnt++;
        n /= (i + 2);
      }
      factors.push_back({i + 2, cnt});
    }
  }
  if (n > 1) {
    factors.push_back({n, 1});
  }
  return factors;
}

// O(K) - Generates the first K multiples of a given number N
vector<ll> get_multiples(ll n, int k) {
  vector<ll> multiples;
  for (int i = 1; i <= k; ++i) {
    multiples.push_back(n * i);
  }
  return multiples;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : abs(a); }
ll lcm(ll a, ll b) { return a == 0 || b == 0 ? 0 : abs(a / gcd(a, b) * b); }
bool coprime(ll a, ll b) { return gcd(a, b) == 1; }


// O(N log N) - Precomputes the divisor count for all numbers up to MAX_N
vector<int> precompute_divisor_counts(int max_n) {
  vector<int> div_counts(max_n + 1, 0);
  for (int i = 1; i <= max_n; ++i) {
    for (int j = i; j <= max_n; j += i) {
      div_counts[j]++;
    }
  }
  return div_counts;
}

// -----------------------------------------------------------------------------
// 2. PRIMALITY UTILITIES
// -----------------------------------------------------------------------------

// O(sqrt(X)) - Highly optimized primality test using 6k +/- 1 optimization
bool is_prime(ll x) {
  if (x < 2) return false;
  if (x % 2 == 0) return x == 2;
  if (x % 3 == 0) return x == 3;
  for (ll i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) return false;
  }
  return true;
}

// O(N log log N) - Sieve of Eratosthenes to generate primes up to N
vector<int> sieve(int n) {
  vector<bool> is_prime_bit(n + 1, true);
  is_prime_bit[0] = is_prime_bit[1] = false;

  for (int i = 2; i * i <= n; ++i) {
    if (is_prime_bit[i]) {
      for (int j = i * i; j <= n; j += i) is_prime_bit[j] = false;
    }
  }

  vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    if (is_prime_bit[i]) primes.push_back(i);
  }
  return primes;
}

// -----------------------------------------------------------------------------
// 3. PERMUTATIONS & COMBINATORICS
// -----------------------------------------------------------------------------

ll factorial(int n) {
  ll res = 1;
  for (int i = 2; i <= n; ++i) res *= i;
  return res;
}

template <class T>
ll count_distinct_permutations(vector<T> arr) {
  sort(arr.begin(), arr.end());
  ll res = factorial(sz(arr));
  map<T, int> freq;
  for (auto x : arr) freq[x]++;
  for (auto p : freq) res /= factorial(p.second);
  return res;
}

bool is_valid_permutation(vector<int> arr) {
  int n = sz(arr);
  vector<bool> seen(n, false);
  for (int x : arr) {
    if (x < 1 || x > n || seen[x - 1]) return false;
    seen[x - 1] = true;
  }
  return true;
}

void print_all_permutations(vector<int> arr) {
  sort(arr.begin(), arr.end());
  do {
    print_vector(arr);
  } while (next_permutation(arr.begin(), arr.end()));
}

void k_permutations(int n, int k) {
  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 1);
  vector<int> sel(k);
  cout << "All " << k << "-permutations of " << n << " elements:\n";
  do {
    copy(arr.begin(), arr.begin() + k, sel.begin());
    print_vector(sel);
    reverse(arr.begin() + k, arr.end());
  } while (next_permutation(arr.begin(), arr.end()));
}

// -----------------------------------------------------------------------------
// 4. SUBSET UTILITIES
// -----------------------------------------------------------------------------

template <class T>
void generate_all_subsets(const vector<T>& arr) {
  int n = sz(arr);
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<T> current_subset;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        current_subset.push_back(arr[i]);
      }
    }
    print_vector(current_subset);
  }
}

template <class T>
void generate_k_subsets(const vector<T>& arr, int k) {
  int n = sz(arr);
  if (k > n || k < 0) return;

  vector<bool> mask(n, false);
  fill(mask.begin(), mask.begin() + k, true);

  do {
    vector<T> current_subset;
    for (int i = 0; i < n; ++i) {
      if (mask[i]) {
        current_subset.push_back(arr[i]);
      }
    }
    print_vector(current_subset);
  } while (prev_permutation(mask.begin(), mask.end()));
}

// -----------------------------------------------------------------------------
// 5. MEX (MINIMUM / MAXIMUM EXCLUDED ELEMENT)
// -----------------------------------------------------------------------------

int get_mex(const vector<int>& arr) {
  set<int> s(arr.begin(), arr.end());
  int m = 0;
  while (s.count(m)) m++;
  return m;
}

int get_mex_fast(const vector<int>& arr) {
  int n = sz(arr);
  vector<bool> present(n + 1, false);
  for (int x : arr) {
    if (x <= n && x >= 0) present[x] = true;
  }
  for (int i = 0; i <= n; ++i) {
    if (!present[i]) return i;
  }
  return n + 1;
}

int max_excluded_element(const vector<int>& arr) {
  if (arr.empty()) return 0;

  int mx = *max_element(arr.begin(), arr.end());
  vector<bool> present(mx + 2, false);
  for (int x : arr) {
    if (x >= 0 && x <= mx + 1) present[x] = true;
  }

  for (int i = mx + 1; i >= 0; --i) {
    if (!present[i]) return i;
  }
  return -1;
}

// -----------------------------------------------------------------------------
// MAIN DEMO
// -----------------------------------------------------------------------------
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Factors & Multiples Demo
  cout << "--- Factors & Multiples Demo ---\n";

  cout << "All factors of 60: ";
  auto facts = get_divisors(60);
  for (auto f : facts) cout << f << " ";
  cout << "\n";

  cout << "Prime factorization of 60: ";
  auto pf = get_prime_factors(60);
  for (auto p : pf) {
    cout << "(" << p.first << "^" << p.second << ") ";
  }
  cout << "\n";

  cout << "First 5 multiples of 12: ";
  auto mults = get_multiples(12, 5);
  for (auto m : mults) cout << m << " ";
  cout << "\n";

  cout << "GCD(24, 36) = " << get_gcd(24, 36) << "\n";
  cout << "LCM(24, 36) = " << get_lcm(24, 36) << "\n";

  return 0;
}