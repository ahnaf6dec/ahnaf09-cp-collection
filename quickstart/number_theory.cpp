// Ultimate number theory collections
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> Mat;

const ll MOD = 1000000007;

template <typename T>
T gcd_array(const vector<T>& arr) {
  if (arr.empty()) return 0;
  T g = arr[0];
  for (size_t i = 1; i < arr.size(); ++i) {
    g = gcd(g, arr[i]);
    if (g == 1) break;  // early stop
  }
  return g;
}

// GCD of array difference a[0] - a[i]

template <typename T>
inline T fast_gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

template <typename T>
T gcd_of_differences(const vector<T>& a) {
  int n = a.size();
  if (n <= 1) return 0;  // no difference
  T g = 0;
  for (int i = 1; i < n; ++i) {
    g = fast_gcd(g, abs(a[i] - a[0]));
    if (g == 1) return 1;  // early stop
  }
  return g;
}
// Example
// int main(){
//     vector<long long> a={10,14,22,34};
//     cout<<gcd_of_differences(a)<<"\n"; // Output: 2
// }

// ---------------- GCD / LCM ----------------
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : abs(a); }
ll lcm(ll a, ll b) { return abs(a / gcd(a, b) * b); }
bool coprime(ll a, ll b) { return gcd(a, b) == 1; }

// ---------------- Binary Exponentiation ----------------

// Note: The following version is compatible with g++ (C++17).
// My default Windows 10 compiler does not fully support the original template
// code.

ll modmul(ll a, ll b, ll m = MOD) {
  ll res = 0;
  a %= m;
  b %= m;
  while (b) {
    if (b & 1) res = (res + a) % m;
    a = (a * 2) % m;
    b >>= 1;
  }
  return res;
}

ll modpow(ll a, ll e, ll m = MOD) {
  ll r = 1;
  while (e) {
    if (e & 1) r = modmul(r, a, m);
    a = modmul(a, a, m);
    e >>= 1;
  }
  return r;
}

ll binpow(ll a, ll e) {
  ll r = 1;
  while (e) {
    if (e & 1) r *= a;
    a *= a;
    e >>= 1;
  }
  return r;
}
ll modpow(ll a, ll e, ll m = MOD) {
  ll r = 1;
  while (e) {
    if (e & 1) r = (__int128)r * a % m;
    a = (__int128)a * a % m;
    e >>= 1;
  }
  return r;
}

// ---------------- Extended GCD / Modular Inverse ----------------
ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1, g = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
ll modinv(ll a, ll m = MOD) { return modpow(a, m - 2, m); }
ll modinv_euclid(ll a, ll m) {
  ll x, y, g = extgcd(a, m, x, y);
  return g != 1 ? -1 : (x % m + m) % m;
}

// ---------------- Modular Operations ----------------
inline ll add(ll a, ll b, ll m = MOD) { return (a + b) % m; }
inline ll sub(ll a, ll b, ll m = MOD) { return (a - b + m) % m; }
inline ll mul(ll a, ll b, ll m = MOD) { return (__int128)a * b % m; }
inline ll divm(ll a, ll b, ll m = MOD) { return mul(a, modinv(b, m), m); }

// ---------------- Factorials / Combinatorics ----------------
vll fact, invfact;
void init_fact(int n, ll m = MOD) {
  fact.assign(n + 1, 1);
  invfact.assign(n + 1, 1);
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
  invfact[n] = modpow(fact[n], m - 2, m);
  for (int i = n; i; i--) invfact[i - 1] = invfact[i] * i % m;
}
ll nCr(int n, int r, ll m = MOD) {
  if (r < 0 || r > n) return 0;
  return fact[n] * invfact[r] % m * invfact[n - r] % m;
}
ll nPr(int n, int r, ll m = MOD) {
  if (r < 0 || r > n) return 0;
  return fact[n] * invfact[n - r] % m;
}
ll nHr(int n, int r, ll m = MOD) {
  if (n == 0 && r > 0) return 0;
  return nCr(n + r - 1, r, m);
}
ll multinomial(vll ks, ll m = MOD) {
  int n = 0;
  for (ll x : ks) n += x;
  ll r = fact[n];
  for (ll x : ks) r = r * invfact[x] % m;
  return r;
}

// ---------------- Sieve / SPF / Prime Factors ----------------
vi spf;
vll primes;
void sieve(int n) {
  spf.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (!spf[i]) spf[i] = i, primes.push_back(i);
    for (ll p : primes) {
      if (p > spf[i] || 1LL * i * p > n) break;
      spf[i * p] = p;
    }
  }
}
vi factorize(int x) {
  vi f;
  while (x > 1) {
    f.push_back(spf[x]);
    x /= spf[x];
  }
  return f;
}

// ---------------- Euler Phi / Divisor Count / Sum ----------------
ll phi(ll n) {
  ll r = n;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      r -= r / p;
    }
  }
  if (n > 1) r -= r / n;
  return r;
}
ll dcount(ll n) {
  ll r = 1;
  for (ll p = 2; p * p <= n; p++) {
    int c = 0;
    while (n % p == 0) {
      c++;
      n /= p;
    }
    r *= (c + 1);
  }
  if (n > 1) r *= 2;
  return r;
}
ll dsum(ll n) {
  ll s = 1;
  for (ll p = 2; p * p <= n; p++) {
    ll c = 1, m = 1;
    while (n % p == 0) {
      n /= p;
      m *= p;
      c++;
    }
    s *= (m * p - 1) / (p - 1);
  }
  if (n > 1) s *= (n + 1);
  return s;
}

// ---------------- CRT (coprime) ----------------
ll crt(vll a, vll m) {
  ll M = 1, res = 0, n = sz(a);
  for (ll x : m) M *= x;
  for (int i = 0; i < n; i++) {
    ll Mi = M / m[i], inv = modinv_euclid(Mi, m[i]);
    res = (res + (__int128)a[i] * Mi % M * inv) % M;
  }
  return (res % M + M) % M;
}

// ---------------- Miller-Rabin / Pollard-Rho ----------------
bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    if (n % p == 0) return n == p;
  ll d = n - 1, s = 0;
  while ((d & 1) == 0) d >>= 1, ++s;
  auto chk = [&](ll a) {
    if (a % n == 0) return true;
    ll x = modpow(a, d, n);
    if (x == 1 || x == n - 1) return true;
    for (int i = 1; i < s; i++) {
      x = (__int128)x * x % n;
      if (x == n - 1) return true;
    }
    return false;
  };
  for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    if (a % n && !chk(a)) return false;
  return true;
}
ll f_rho(ll x, ll c, ll m) { return (mul(x, x, m) + c) % m; }
ll rho(ll n) {
  if (n % 2 == 0) return 2;
  std::mt19937_64 rng(
      std::chrono::steady_clock::now().time_since_epoch().count());
  while (1) {
    ll x = std::uniform_int_distribution<ll>(2, n - 2)(rng);
    ll y = x, c = std::uniform_int_distribution<ll>(1, n - 1)(rng), d = 1;
    while (d == 1) {
      x = f_rho(x, c, n);
      y = f_rho(f_rho(y, c, n), c, n);
      d = gcd(std::abs(x - y), n);
    }
    if (d != n) return d;
  }
}

// ---------------- Discrete Logarithm ----------------
ll dlog(ll a, ll b, ll m) {
  a %= m;
  b %= m;
  ll n = std::sqrt(m) + 1;
  std::unordered_map<ll, ll> vals;
  ll an = 1;
  for (int i = 0; i < n; i++) an = an * a % m;
  ll cur = b;
  for (int q = 0; q < n; q++) {
    vals[cur] = q;
    cur = cur * a % m;
  }
  cur = 1;
  for (int p = 1; p <= n + 1; p++) {
    cur = cur * an % m;
    if (vals.count(cur)) return n * p - vals[cur];
  }
  return -1;
}

// ---------------- Matrix Operations ----------------
Mat mat_add(const Mat& A, const Mat& B, ll m = MOD) {
  int n = sz(A), k = sz(A[0]);
  Mat C(n, vll(k));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++) C[i][j] = (A[i][j] + B[i][j]) % m;
  return C;
}
Mat mat_sub(const Mat& A, const Mat& B, ll m = MOD) {
  int n = sz(A), k = sz(A[0]);
  Mat C(n, vll(k));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++) C[i][j] = (A[i][j] - B[i][j] + m) % m;
  return C;
}
Mat mat_mul(const Mat& A, const Mat& B, ll m = MOD) {
  int n = sz(A), k = sz(A[0]), p = sz(B[0]);
  Mat C(n, vll(p, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < p; j++)
      for (int x = 0; x < k; x++)
        C[i][j] = (C[i][j] + A[i][x] * B[x][j] % m) % m;
  return C;
}
Mat mat_pow(Mat A, ll e, ll m = MOD) {
  int n = sz(A);
  Mat R(n, vll(n, 0));
  for (int i = 0; i < n; i++) R[i][i] = 1;
  while (e) {
    if (e & 1) R = mat_mul(R, A, m);
    A = mat_mul(A, A, m);
    e >>= 1;
  }
  return R;
}
ll fib(ll n, ll m = MOD) {
  if (n == 0) return 0;
  Mat F = {{1, 1}, {1, 0}};
  Mat R = mat_pow(F, n - 1, m);
  return R[0][0];
}

// ---------------- Extra Helpers ----------------
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
ll floor_div(ll a, ll b) { return a / b; }
bool is_power_of_two(ll n) { return n > 0 && (n & (n - 1)) == 0; }

// More useful stuff v2

// ---------------- Modular Utilities ----------------
inline ll norm(ll a, ll m = MOD) {
  a %= m;
  if (a < 0) a += m;
  return a;
}
inline ll modadd(ll a, ll b, ll m = MOD) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
inline ll modsub(ll a, ll b, ll m = MOD) {
  a -= b;
  if (a < 0) a += m;
  return a;
}
inline ll modmul(ll a, ll b, ll m = MOD) { return (__int128)a * b % m; }
inline ll modpow_sum(ll a, ll n, ll m = MOD) {  // (1 + a + a^2 + ... + a^(n-1))
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n % 2) return (1 + a * modpow_sum(a, n - 1, m)) % m;
  ll half = modpow_sum(a, n / 2, m);
  ll p = modpow(a, n / 2, m);
  return (half + modmul(half, p, m)) % m;
}

// ---------------- Binary GCD (Stein's Algorithm) ----------------
ll binary_gcd(ll a, ll b) {
  if (!a) return abs(b);
  if (!b) return abs(a);
  int shift = __builtin_ctzll(a | b);
  a >>= __builtin_ctzll(a);
  do {
    b >>= __builtin_ctzll(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

// ---------------- Segmented Sieve ----------------
vll seg_sieve(ll L, ll R) {
  ll lim = sqrt(R) + 1;
  vector<bool> mark(R - L + 1, true);
  vector<bool> base(lim + 1, false);
  vector<ll> ps;
  for (ll i = 2; i <= lim; i++)
    if (!base[i]) {
      ps.push_back(i);
      for (ll j = i * i; j <= lim; j += i) base[j] = true;
    }
  for (ll p : ps) {
    for (ll j = max(p * p, (L + p - 1) / p * p); j <= R; j += p)
      mark[j - L] = false;
  }
  if (L == 1) mark[0] = false;
  vll primes;
  for (ll i = 0; i <= R - L; i++)
    if (mark[i]) primes.push_back(L + i);
  return primes;
}

// ---------------- Factorization (unordered_map version) ----------------
map<ll, int> factorize_ll(ll n) {
  map<ll, int> f;
  while (n > 1 && n % 2 == 0) {
    f[2]++;
    n /= 2;
  }
  for (ll i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      f[i]++;
      n /= i;
    }
  }
  if (n > 1) f[n]++;
  return f;
}

// ---------------- All Divisors ----------------
vll divisors(ll n) {
  vll d;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      d.push_back(i);
      if (i * i != n) d.push_back(n / i);
    }
  }
  sort(d.begin(), d.end());
  return d;
}

// ---------------- Sieve for Totient & Möbius ----------------
const int MAXN = 1e6 + 5;
int phi_sieve[MAXN], mu_sieve[MAXN];
bool comp_sieve[MAXN];
void precompute_phi_mu() {
  for (int i = 1; i < MAXN; i++) phi_sieve[i] = i, mu_sieve[i] = 1;
  for (int i = 2; i < MAXN; i++) {
    if (!comp_sieve[i]) {
      for (int j = i; j < MAXN; j += i) {
        comp_sieve[j] = 1;
        phi_sieve[j] = phi_sieve[j] / i * (i - 1);
        mu_sieve[j] *= -1;
      }
      for (long long j = 1LL * i * i; j < MAXN; j += 1LL * i * i)
        mu_sieve[j] = 0;
    }
  }
}

// ---------------- Fibonacci (Fast Doubling) ----------------
pair<ll, ll> fib_doubling(ll n, ll m = MOD) {
  if (n == 0) return {0, 1};
  auto [a, b] = fib_doubling(n >> 1, m);
  ll c = modmul(a, (2 * b % m - a + m) % m, m);
  ll d = (modmul(a, a, m) + modmul(b, b, m)) % m;
  if (n & 1)
    return {d, (c + d) % m};
  else
    return {c, d};
}
ll fib_fast(ll n, ll m = MOD) { return fib_doubling(n, m).first; }

// ---------------- Modular Geometric Sum ----------------
// Sum = a^0 + a^1 + ... + a^(n-1)
ll modgeom(ll a, ll n, ll m = MOD) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n % 2 == 0) {
    ll half = modgeom(a, n / 2, m);
    ll p = modpow(a, n / 2, m);
    return modmul(half, modadd(1, p, m), m);
  } else {
    return modadd(1, modmul(a, modgeom(a, n - 1, m), m), m);
  }
}

// ---------------- Modular Linear Equation: ax ≡ b (mod m) ----------------
ll mod_linear(ll a, ll b, ll m) {
  ll x, y, g = extgcd(a, m, x, y);
  if (b % g != 0) return -1;  // no solution
  x = (x * (b / g)) % m;
  return (x % m + m) % m;
}

// ---------------- Lucas Theorem (nCr mod prime) ----------------
ll nCr_lucas(ll n, ll r, ll p = MOD) {
  if (r == 0) return 1;
  return (nCr_lucas(n / p, r / p, p) * nCr(n % p, r % p, p)) % p;
}

// ---------------- Modular Equation Solver (for a set) ----------------
vector<ll> solve_congruences(vll a, vll m) {
  // all mod not necessarily coprime
  // pairwise reduce using CRT for coprime sets only
  return {};  // to-do: placeholder if needed
}

// ---------------- Perfect Square / Integer sqrt ----------------
ll isqrt(ll n) {
  ll x = sqrtl(n);
  while (x * x > n) --x;
  while ((x + 1) * (x + 1) <= n) ++x;
  return x;
}
bool is_square(ll n) {
  if (n < 0) return false;
  ll r = isqrt(n);
  return r * r == n;
}

// ---------------- Sum of Divisors up to N ----------------
vector<ll> divisor_sum_prefix(int n) {
  vector<ll> d(n + 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) d[j] += i;
  return d;
}

// Harmonic Stuff
// ---------- Harmonic Series ----------
double harmonic(int n) {
  double sum = 0.0;
  for (int i = 1; i <= n; ++i) sum += 1.0 / i;
  return sum;
}

double harmonicApprox(int n) {
  const double gamma = 0.5772156649015328606;
  return log(n) + gamma;
}

// ---------- Probability ----------
double probability(int favorable, int total) {
  return (double)favorable / total;
}

double conditionalProb(double pA_and_B, double pB) { return pA_and_B / pB; }

double expectedValue(const vector<double>& values,
                     const vector<double>& probs) {
  double E = 0.0;
  for (int i = 0; i < values.size(); ++i) E += values[i] * probs[i];
  return E;
}

double binomialProb(int n, int r, double p) {
  double comb = 1;
  for (int i = 1; i <= r; ++i) comb *= (n - i + 1) / (double)i;
  return comb * pow(p, r) * pow(1 - p, n - r);
}

// ---------- Statistics ----------
double mean(const vector<double>& v) {
  double sum = 0;
  for (double x : v) sum += x;
  return sum / v.size();
}

double median(vector<double> v) {
  sort(v.begin(), v.end());
  int n = v.size();
  if (n % 2) return v[n / 2];
  return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

double mode(const vector<double>& v) {
  unordered_map<double, int> freq;
  for (double x : v) freq[x]++;
  double modeVal = v[0];
  int maxFreq = 0;
  for (auto& [x, f] : freq)
    if (f > maxFreq) maxFreq = f, modeVal = x;
  return modeVal;
}

double variance(const vector<double>& v) {
  double m = mean(v);
  double sum = 0;
  for (double x : v) sum += (x - m) * (x - m);
  return sum / v.size();
}

double stddev(const vector<double>& v) { return sqrt(variance(v)); }

vector<double> normalize(vector<double> v) {
  double total = accumulate(v.begin(), v.end(), 0.0);
  for (double& x : v) x /= total;
  return v;
}

double correlation(const vector<double>& x, const vector<double>& y) {
  int n = x.size();
  double meanX = mean(x), meanY = mean(y);
  double num = 0, denX = 0, denY = 0;
  for (int i = 0; i < n; ++i) {
    num += (x[i] - meanX) * (y[i] - meanY);
    denX += (x[i] - meanX) * (x[i] - meanX);
    denY += (y[i] - meanY) * (y[i] - meanY);
  }
  return num / sqrt(denX * denY);
}

// ------------------------------------------------------------
// Self-Test: Verify Core Functions of the Number Theory Toolkit
// ------------------------------------------------------------
void test_all_utils() {
  cout << "---------- Number Theory & Matrix Library Test ----------\n\n";

  // --- GCD / LCM ---
  cout << "[GCD/LCM]\n";
  cout << "gcd(48,18) = " << gcd(48, 18) << "  (expected 6)\n";
  cout << "lcm(12,18) = " << lcm(12, 18) << "  (expected 36)\n";
  cout << "coprime(7,20) = " << coprime(7, 20) << "\n\n";

  // --- Modular arithmetic ---
  cout << "[Modular Arithmetic]\n";
  cout << "modpow(3,5,1e9+7) = " << modpow(3, 5) << "  (expected 243)\n";
  cout << "modinv(3) = " << modinv(3) << "  (check 3*x % MOD == 1)\n";
  cout << "divm(10,2) = " << divm(10, 2) << "\n\n";

  // --- Factorial / Combinatorics ---
  init_fact(10);
  cout << "[Factorials / Combinatorics]\n";
  cout << "fact[5] = " << fact[5] << "  (expected 120)\n";
  cout << "nCr(10,3) = " << nCr(10, 3) << "  (expected 120)\n";
  cout << "nPr(10,3) = " << nPr(10, 3) << "  (expected 720)\n";
  cout << "nHr(5,3) = " << nHr(5, 3) << "  (expected 35)\n";
  vll ks = {2, 1, 2};
  cout << "multinomial({2,1,2}) = " << multinomial(ks) << "\n\n";

  // --- GCD of Array ---
  vector<ll> arr = {10, 14, 22, 34};
  cout << "[GCD of Array / Differences]\n";
  cout << "gcd_array(arr) = " << gcd_array(arr) << "\n";
  cout << "gcd_of_differences(arr) = " << gcd_of_differences(arr) << "\n\n";

  // --- Binary GCD ---
  cout << "[Binary GCD]\n";
  cout << "binary_gcd(48,18) = " << binary_gcd(48, 18) << "  (expected 6)\n\n";

  // --- Segmented Sieve ---
  cout << "[Segmented Sieve 10..30]\n";
  auto segp = seg_sieve(10, 30);
  for (auto p : segp) cout << p << " ";
  cout << "\n\n";

  // --- Factorization / Divisors ---
  cout << "[Factorization / Divisors]\n";
  auto f = factorize_ll(360);
  cout << "360 = ";
  for (auto [p, e] : f) cout << p << "^" << e << " ";
  cout << "\nDivisors of 36: ";
  auto d = divisors(36);
  for (auto x : d) cout << x << " ";
  cout << "\n\n";

  // --- Euler Phi & Möbius ---
  precompute_phi_mu();
  cout << "[Euler Phi & Möbius]\n";
  cout << "phi(36) = " << phi_sieve[36] << "  (expected 12)\n";
  cout << "mu(36) = " << mu_sieve[36] << "  (expected 0)\n\n";

  // --- Fibonacci ---
  cout << "[Fibonacci]\n";
  cout << "fib(10) = " << fib(10) << "  (expected 55)\n";
  cout << "fib_fast(10) = " << fib_fast(10) << "  (expected 55)\n\n";

  // --- Modular Linear Equation ---
  cout << "[Modular Linear Equation]\n";
  cout << "Solve 3x ≡ 4 (mod 7): x = " << mod_linear(3, 4, 7)
       << "  (check: (3*x)%7 == 4)\n\n";

  // --- Lucas Theorem ---
  cout << "[Lucas Theorem]\n";
  cout << "nCr_lucas(1000,20,MOD) = " << nCr_lucas(1000, 20) << "\n\n";

  // --- Geometric Series Mod ---
  cout << "[Geometric Series Mod]\n";
  cout << "1 + 2 + 4 + 8 + 16 (mod 1e9+7) = " << modgeom(2, 5)
       << " (expected 31)\n\n";

  // --- Integer sqrt / is_square ---
  cout << "[Integer sqrt / Perfect square]\n";
  cout << "isqrt(50) = " << isqrt(50) << "  (expected 7)\n";
  cout << "is_square(49) = " << is_square(49) << "\n";
  cout << "is_square(50) = " << is_square(50) << "\n\n";

  // --- Matrix Exponentiation / Fibonacci check ---
  cout << "[Matrix Power Test]\n";
  Mat F = {{1, 1}, {1, 0}};
  Mat R = mat_pow(F, 10);
  cout << "F^10 (mod 1e9+7):\n";
  for (auto& row : R) {
    for (auto x : row) cout << x << " ";
    cout << "\n";
  }

  cout << "\n---------- End of Test ----------\n";
}

// Optional: Run when needed
// int main() { ios::sync_with_stdio(false); cin.tie(nullptr); test_all_utils();
// }
