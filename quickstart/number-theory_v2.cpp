#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// CONFIGURATION, TYPEDEFS & MACROS
// -----------------------------------------------------------------------------
#define sz(x) ((int)(x).size())
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using Mat = vector<vll>;

const ll MOD = 1000000007;
const int MAXN = 1e6 + 5;
const double EPS = 1e-9;

// -----------------------------------------------------------------------------
// 1. COORDINATE GEOMETRY UTILITIES
// -----------------------------------------------------------------------------
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

/* Use Case: Finding the perimeter of a polygon or tracking straight line
 * distance. */
double euclidean_distance(Point a, Point b) {
  return std::hypot(a.x - b.x, a.y - b.y);
}

/* Use Case: Grid-based movement problems (e.g., Minimum moves on a
 * chessboard/grid). */
double manhattan_distance(Point a, Point b) {
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

/* Use Case: Checking line directions or finding perpendicular vectors. */
double get_slope(Point a, Point b) {
  if (std::abs(a.x - b.x) < EPS) return DBL_MAX;
  return (b.y - a.y) / (b.x - a.x);
}

/* Use Case: Finding the center pivot of a line segment. */
Point get_midpoint(Point a, Point b) {
  return Point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
}

/* Use Case: Finding a point weighted towards an end (e.g., Center of mass). */
Point section_formula(Point a, Point b, double m, double n) {
  return Point((m * b.x + n * a.x) / (m + n), (m * b.y + n * a.y) / (m + n));
}

/* Use Case: Eliminating cross-slope calculations which cause precision loss. */
bool are_collinear(Point a, Point b, Point c) {
  return std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) <
         EPS;
}

/* Use Case: Finding where two line paths cross on a map plane. */
tuple<double, double, double> get_line_equation(Point p1, Point p2) {
  double A = p2.y - p1.y;
  double B = p1.x - p2.x;
  double C = -(A * p1.x + B * p1.y);
  return make_tuple(A, B, C);
}

/* Use Case: Raytracing or physics bouncing simulations. */
Point reflect_point(Point p, double A, double B, double C) {
  double temp = -2 * (A * p.x + B * p.y + C) / (A * A + B * B);
  return Point(p.x + A * temp, p.y + B * temp);
}

// -----------------------------------------------------------------------------
// 2. BASIC & ARRAY ARITHMETIC
// -----------------------------------------------------------------------------
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : abs(a); }
ll lcm(ll a, ll b) { return a == 0 || b == 0 ? 0 : abs(a / gcd(a, b) * b); }
bool coprime(ll a, ll b) { return gcd(a, b) == 1; }

/* Use Case: High-speed GCD calculations inside inner loops of extreme
 * constraints. */
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

/* Use Case: Simplifying an entire fraction array to its relative prime
 * components. */
template <typename T>
T gcd_array(const vector<T>& arr) {
  if (arr.empty()) return 0;
  T g = arr[0];
  for (size_t i = 1; i < arr.size(); ++i) {
    g = std::gcd(g, arr[i]);
    if (g == 1) break;
  }
  return g;
}

/* Use Case: Codeforces style problem - "Make array equal by adding X
 * repeatedly". */
template <typename T>
T gcd_of_differences(const vector<T>& a) {
  int n = sz(a);
  if (n <= 1) return 0;
  T g = 0;
  for (int i = 1; i < n; ++i) {
    g = std::gcd(g, abs(a[i] - a[0]));
    if (g == 1) return 1;
  }
  return g;
}

// -----------------------------------------------------------------------------
// 3. MODULAR ARITHMETIC & EXPONENTIATION
// -----------------------------------------------------------------------------
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

/* Use Case: Computing quick powers or Fermat's Little Theorem configurations.
 */
ll modpow(ll a, ll e, ll m = MOD) {
  ll r = 1;
  a = norm(a, m);
  while (e > 0) {
    if (e & 1) r = (__int128)r * a % m;
    a = (__int128)a * a % m;
    e >>= 1;
  }
  return r;
}

/* Use Case: Exact integer powers where constraints are guarantee-bound within
 * 64 bits. */
ll binpow(ll a, ll e) {
  ll r = 1;
  while (e > 0) {
    if (e & 1) r *= a;
    a *= a;
    e >>= 1;
  }
  return r;
}

// -----------------------------------------------------------------------------
// 4. EXTENDED GCD & MODULAR INVERSE
// -----------------------------------------------------------------------------
/* Use Case: Solving linear equations like Ax + By = C. */
ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll g = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

/* Use Case: Modular divisions when Modulo is a standard prime number (1e9+7).
 */
ll modinv(ll a, ll m = MOD) { return modpow(a, m - 2, m); }

/* Use Case: Modular divisions when Modulo is NOT a prime number. */
ll modinv_euclid(ll a, ll m) {
  ll x, y;
  ll g = extgcd(a, m, x, y);
  return g != 1 ? -1 : (x % m + m) % m;
}
inline ll divm(ll a, ll b, ll m = MOD) { return modmul(a, modinv(b, m), m); }

// -----------------------------------------------------------------------------
// 5. COMBINATORICS
// -----------------------------------------------------------------------------
vll fact, invfact;
/* Use Case: Call this at initialization to allow O(1) nCr computations. */
void init_fact(int n, ll m = MOD) {
  fact.assign(n + 1, 1);
  invfact.assign(n + 1, 1);
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
  invfact[n] = modinv(fact[n], m);
  for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i % m;
}

/* Use Case: Ways to choose R items out of N unique components. */
ll nCr(int n, int r, ll m = MOD) {
  if (r < 0 || r > n) return 0;
  return fact[n] * invfact[r] % m * invfact[n - r] % m;
}

/* Use Case: Order-based permutations selecting R elements from N. */
ll nPr(int n, int r, ll m = MOD) {
  if (r < 0 || r > n) return 0;
  return fact[n] * invfact[n - r] % m;
}

/* Use Case: Selecting identical tasks/items across distinct buckets. */
ll nHr(int n, int r, ll m = MOD) {
  if (n == 0 && r > 0) return 0;
  return nCr(n + r - 1, r, m);
}

/* Use Case: Anagram combinations (e.g., arrangements of string "BOOKKEEPER").
 */
ll multinomial(const vll& ks, ll m = MOD) {
  int n = 0;
  for (ll x : ks) n += x;
  ll r = fact[n];
  for (ll x : ks) r = r * invfact[x] % m;
  return r;
}

/* Use Case: Computing combinations when N, R are huge, but Modulo is a tiny
 * prime. */
ll nCr_lucas(ll n, ll r, ll p = MOD) {
  if (r == 0) return 1;
  return (nCr_lucas(n / p, r / p, p) * nCr(n % p, r % p, p)) % p;
}

// -----------------------------------------------------------------------------
// 6. SIEVES & PRIMALITY TESTING
// -----------------------------------------------------------------------------
vi spf;
vll primes;
int phi_sieve[MAXN], mu_sieve[MAXN];
bool comp_sieve[MAXN];

/* Use Case: Instantly factorizes numbers queries up to 10^6 in O(log N) time.
 */
void linear_sieve(int n) {
  spf.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (!spf[i]) {
      spf[i] = i;
      primes.push_back(i);
    }
    for (ll p : primes) {
      if (p > spf[i] || i * p > n) break;
      spf[i * p] = p;
    }
  }
}

/* Use Case: Unpacks numbers into prime factors using linear sieve
 * precalculations. */
vi factorize_spf(int x) {
  vi f;
  while (x > 1) {
    f.push_back(spf[x]);
    x /= spf[x];
  }
  return f;
}

/* Use Case: Precomputing answers for range coprime pairs or Mobius
 * inclusion-exclusion queries. */
void precompute_phi_mu() {
  for (int i = 1; i < MAXN; i++) {
    phi_sieve[i] = i;
    mu_sieve[i] = 1;
  }
  for (int i = 2; i < MAXN; i++) {
    if (!comp_sieve[i]) {
      for (int j = i; j < MAXN; j += i) {
        comp_sieve[j] = true;
        phi_sieve[j] = phi_sieve[j] / i * (i - 1);
        mu_sieve[j] *= -1;
      }
      for (ll j = 1LL * i * i; j < MAXN; j += 1LL * i * i) mu_sieve[j] = 0;
    }
  }
}

/* Use Case: Sifting primes in ranges where window bounds are huge (e.g., L, R
 * up to 10^12). */
vll seg_sieve(ll L, ll R) {
  ll lim = sqrt(R) + 1;
  vector<bool> mark(R - L + 1, true);
  vector<bool> base(lim + 1, false);
  vector<ll> ps;
  for (ll i = 2; i <= lim; i++) {
    if (!base[i]) {
      ps.push_back(i);
      for (ll j = i * i; j <= lim; j += i) base[j] = true;
    }
  }
  for (ll p : ps) {
    for (ll j = max(p * p, (L + p - 1) / p * p); j <= R; j += p)
      mark[j - L] = false;
  }
  if (L == 1) mark[0] = false;
  vll seg_primes;
  for (ll i = 0; i <= R - L; i++)
    if (mark[i]) seg_primes.push_back(L + i);
  return seg_primes;
}

/* Use Case: Deterministic primality screening for isolated long long integers.
 */
bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    if (n % p == 0) return n == p;
  ll d = n - 1;
  int s = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    ++s;
  }
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

/* Use Case: Highly optimized factorization engine for massive integers (up to
 * 10^18). */
ll f_rho(ll x, ll c, ll m) { return (modmul(x, x, m) + c) % m; }
ll rho(ll n) {
  if (n % 2 == 0) return 2;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  while (true) {
    ll x = uniform_int_distribution<ll>(2, n - 2)(rng);
    ll y = x, c = uniform_int_distribution<ll>(1, n - 1)(rng), d = 1;
    while (d == 1) {
      x = f_rho(x, c, n);
      y = f_rho(f_rho(y, c, n), c, n);
      d = std::gcd(abs(x - y), n);
    }
    if (d != n) return d;
  }
}

// -----------------------------------------------------------------------------
// 7. GENERAL VALUE FACTORIZATION & EQUATION SOLVERS
// -----------------------------------------------------------------------------
/* Use Case: General factorization of standalone integers outside sieve limits.
 */
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

/* Use Case: Finding all exact factors of a target score/value. */
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

/* Use Case: Counting numbers up to N that do not share any common factors with
 * N. */
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

/* Use Case: Aligning multiple cyclical offsets (e.g., matching train arrivals
 * with different intervals). */
ll crt(const vll& a, const vll& m) {
  ll M = 1, res = 0, n = sz(a);
  for (ll x : m) M *= x;
  for (int i = 0; i < n; i++) {
    ll Mi = M / m[i], inv = modinv_euclid(Mi, m[i]);
    res = (res + (__int128)a[i] * Mi % M * inv) % M;
  }
  return (res % M + M) % M;
}

/* Use Case: Solving complex exponential log matching scenarios (a^x = b mod m).
 */
ll dlog(ll a, ll b, ll m) {
  a %= m;
  b %= m;
  ll n = sqrt(m) + 1;
  unordered_map<ll, ll> vals;
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

/* Use Case: Finding base factors within a modulo equation loop. */
ll mod_linear(ll a, ll b, ll m) {
  ll x, y;
  ll g = extgcd(a, m, x, y);
  if (b % g != 0) return -1;
  x = (x * (b / g)) % m;
  return (x % m + m) % m;
}

// -----------------------------------------------------------------------------
// 8. SEQUENCES & SERIES
// -----------------------------------------------------------------------------
/* Use Case: Fetching the Nth Fibonacci number instantly when N is huge (up to
 * 10^18). */
pair<ll, ll> fib_doubling(ll n, ll m = MOD) {
  if (n == 0) return {0, 1};
  auto [a, b] = fib_doubling(n >> 1, m);
  ll c = modmul(a, (2 * b % m - a + m) % m, m);
  ll d = (modmul(a, a, m) + modmul(b, b, m)) % m;
  if (n & 1) return {d, (c + d) % m};
  return {c, d};
}
ll fib_fast(ll n, ll m = MOD) { return fib_doubling(n, m).first; }

/* Use Case: Total sum of exponentially expanding sequences under modulo. */
ll modgeom(ll a, ll n, ll m = MOD) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n % 2 == 0) {
    ll half = modgeom(a, n / 2, m);
    ll p = modpow(a, n / 2, m);
    return modmul(half, modadd(1, p, m), m);
  }
  return modadd(1, modmul(a, modgeom(a, n - 1, m), m), m);
}

/* Use Case: Counting overall divisors iteratively for arrays up to N. */
vector<ll> divisor_sum_prefix(int n) {
  vector<ll> d(n + 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) d[j] += i;
  return d;
}

// -----------------------------------------------------------------------------
// 9. MATRIX EXPONENTIATION UTILITIES
// -----------------------------------------------------------------------------
Mat mat_add(const Mat& A, const Mat& B, ll m = MOD) {
  int n = sz(A), k = sz(A[0]);
  Mat C(n, vll(k));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++) C[i][j] = (A[i][j] + B[i][j]) % m;
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

/* Use Case: Solving linear recurrences or counting paths of length K in graphs.
 */
Mat mat_pow(Mat A, ll e, ll m = MOD) {
  int n = sz(A);
  Mat R(n, vll(n, 0));
  for (int i = 0; i < n; i++) R[i][i] = 1;
  while (e > 0) {
    if (e & 1) R = mat_mul(R, A, m);
    A = mat_mul(A, A, m);
    e >>= 1;
  }
  return R;
}

// -----------------------------------------------------------------------------
// 10. FLOOR / CEIL / SQUARE ROOT HELPERS
// -----------------------------------------------------------------------------
/* Use Case: Division adjustments avoiding dangerous float conversion errors. */
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
ll floor_div(ll a, ll b) { return a / b; }
// ---------------------------------------
/* FLOOR: ⌊a/b⌋
   use: math formulas, negatives safe, number theory */
ll fl(ll a, ll b) {
  ll q = a / b, r = a % b;
  if (r && ((r > 0) != (b > 0))) --q;
  return q;
}

/* CEIL: ⌈a/b⌉
   use: minimum needed, groups, days, operations */
ll cl(ll a, ll b) {
  ll q = a / b, r = a % b;
  if (r && ((r > 0) == (b > 0))) ++q;
  return q;
}

/* ROUND: nearest integer
   use: only when statement says "round/nearest" */
ll rd(ll a, ll b) {
  if ((a ^ b) >= 0) return (a + b / 2) / b;
  return (a - b / 2) / b;
}

bool is_power_of_two(ll n) { return n > 0 && (n & (n - 1)) == 0; }
// n << k = n * 2^k
// n >> k = n / 2^k
// (a ^ b) == 0 [a value not eql to b value]
// (a ^ b) != 0 [a value not eql to b value]
// (n & 1) [n is odd]
// !(n & 1) [n is even]
// a > 0 -> a is positive 
// a < 0 -> a is negative
// a == 0 -> a is 0

// divisible by 2  → last digit even
// divisible by 3  → sum of digits divisible by 3
// divisible by 4  → last 2 digits divisible by 4
// divisible by 5  → last digit 0 or 5
// divisible by 6  → divisible by 2 and 3
// divisible by 8  → last 3 digits divisible by 8
// divisible by 9  → sum of digits divisible by 9
// divisible by 10 → last digit 0
 
/* Use Case: Pure integer calculations avoiding precision issues with long
 * doubles. */
ll isqrt(ll n) {
  ll x = sqrtl(n);
  while (x * x > n) --x;
  while ((x + 1) * (x + 1) <= n) ++x;
  return x;
}
bool is_square(ll n) { return n >= 0 && isqrt(n) * isqrt(n) == n; }

// -----------------------------------------------------------------------------
// 11. STATISTICS & PROBABILITY MATHEMATICS
// -----------------------------------------------------------------------------
/* Use Case: Calculating graph node probabilities or tree depth estimations. */
double harmonic(int n) {
  double sum = 0.0;
  for (int i = 1; i <= n; ++i) sum += 1.0 / i;
  return sum;
}
double harmonicApprox(int n) { return log(n) + 0.5772156649015328606; }

/* Use Case: Strategy evaluation games with randomized rewards. */
double expectedValue(const vector<double>& values,
                     const vector<double>& probs) {
  double E = 0.0;
  for (size_t i = 0; i < values.size(); ++i) E += values[i] * probs[i];
  return E;
}

/* Use Case: Target tracking distributions (e.g., probability of hitting a
 * target R times in N attempts). */
double binomialProb(int n, int r, double p) {
  double comb = 1;
  for (int i = 1; i <= r; ++i) comb *= (n - i + 1) / (double)i;
  return comb * pow(p, r) * pow(1 - p, n - r);
}

/* Use Case: Average score compilation. */
double mean(const vector<double>& v) {
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

/* Use Case: Outlier-robust middle ranking calculation. */
double median(vector<double> v) {
  sort(v.begin(), v.end());
  int n = sz(v);
  return (n % 2) ? v[n / 2] : (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

/* Use Case: Stability and deviation modeling. */
double variance(const vector<double>& v) {
  double m = mean(v), sum = 0;
  for (double x : v) sum += (x - m) * (x - m);
  return sum / v.size();
}
double stddev(const vector<double>& v) { return sqrt(variance(v)); }

// -----------------------------------------------------------------------------
// MAIN BOILERPLATE
// -----------------------------------------------------------------------------
int main() {
  // Optimizing I/O performance
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
}
