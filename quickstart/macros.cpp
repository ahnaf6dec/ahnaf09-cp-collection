// In the Name of Allah
// Author : ahnaf09

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// 1. CORE CONFIGURATION & FAST IO
// -----------------------------------------------------------------------------
#define FASTIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr)
#define endl '\n'
#define flush endl << std::flush

// -----------------------------------------------------------------------------
// 2. TYPE ALIASES & CUSTOM CONTAINERS
// -----------------------------------------------------------------------------
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;

using t3i = tuple<int, int, int>;
using t3l = tuple<ll, ll, ll>;

template <typename T>
using pq_max = priority_queue<T>;
template <typename T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

// Legacy lowercase aliases from version 2
#define pq_max(a) priority_queue<a>
#define pq_min(a) priority_queue<a, vector<a>, greater<a>>

// -----------------------------------------------------------------------------
// 3. ALGORITHMIC CONSTANTS
// -----------------------------------------------------------------------------
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const ld PI = 3.14159265358979323846;
const ld EPS = 1e-9;

// Primary modular architectures
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const ll MOD2 = 1000000009;
const ll MOD3 = 1e9 + 21;

// Grid directions (Left, Right, Down, Up, Diagonals)
const int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

// -----------------------------------------------------------------------------
// 4. SHORTHAND GENERAL MACROS
// -----------------------------------------------------------------------------
#define ff first
#define ss second
#define fi first
#define se second
#define sp ' '

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ins insert
#define mkp make_pair

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define mems(a, x) memset((a), (x), sizeof(a))

// Direct response printing
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yO "YES\n"
#define nO "NO\n"
#define yo "Yes\n"
#define no "No\n"

// -----------------------------------------------------------------------------
// 5. VECTOR MATH & SEARCH QUERIES
// -----------------------------------------------------------------------------
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v), 0LL)
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), (x).erase(unique(all(x)), (x).end()), (x).shrink_to_fit()

// Standard loop expansions
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define RREP(i, a, b) for (int i = (a); i >= (b); --i)
#define FOREACH(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define FORE(a, v) for (auto& a : v)

// -----------------------------------------------------------------------------
// 6. BITWISE MANIPULATION INTERFACES
// -----------------------------------------------------------------------------
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define SETBIT(x, i) ((x) | (1LL << (i)))
#define CLEARBIT(x, i) ((x) & ~(1LL << (i)))
#define FLIPBIT(x, i) ((x) ^ (1LL << (i)))
#define LOWBIT(x) ((x) & -(x))
#define POW2(x) (1LL << (x))

// -----------------------------------------------------------------------------
// 7. INLINE MATH, BOUNDS & SOLVERS
// -----------------------------------------------------------------------------
#define sq(x) ((x) * (x))
#define mid ((l + r) >> 1)

#define CHKMIN(a, b) \
  if ((a) > (b)) (a) = (b)
#define CHKMAX(a, b) \
  if ((a) < (b)) (a) = (b)
#define ckmin(a, b) (a) = min((a), (b))
#define ckmax(a, b) (a) = max((a), (b))

#define MODADD(a, b, m) (((a) % (m) + (b) % (m)) % (m))
#define MODSUB(a, b, m) ((((a) % (m) - (b) % (m)) + (m)) % (m))
#define MODMUL(a, b, m) ((((a) % (m)) * ((b) % (m))) % (m))
#define MODINV(a, m) binpow(a, (m) - 2, m)  // Only valid if m is prime

/* Use Case: High-speed modular exponentiation. */
inline ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (__int128)res * a % m;
    a = (__int128)a * a % m;
    b >>= 1;
  }
  return res;
}

/* Use Case: Overflow-safe integer division rounding upwards. */
inline ll ceildiv(ll a, ll b) { return a / b + (a % b != 0); }

/* Use Case: Digit transformations for digital root or math puzzles. */
inline ll digitsum(ll a) {
  ll b = 0;
  while (a > 0) {
    b += a % 10;
    a /= 10;
  }
  return b;
}

/* Use Case: Small permutation counting or localized factorial math. */
inline ll factorial(ll a) {
  ll b = 1;
  while (a > 0) {
    b *= a;
    a--;
  }
  return b;
}

/* Use Case: Geometric and square properties parsing. */
inline bool isPerfectSquare(ll x) {
  if (x >= 0) {
    ll sr = sqrtl(x);
    return (sr * sr == x);
  }
  return false;
}

/* Use Case: Standard isolated fallback primality screening. */
inline bool isPrime(ll n) {
  if (n <= 1) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

/* Use Case: Palindromic integer checks. */
inline bool isPal(ll x) {
  string s = "";
  while (x) {
    s += to_string(x % 10);
    x /= 10;
  }
  string t = s;
  reverse(all(s));
  return s == t;
}

/* Use Case: Indexed-based uppercase/lowercase character conversion. */
inline char letter(ll n) {
  static const string alphabet =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return (n >= 0 && n < sz(alphabet)) ? alphabet[n] : '\0';
}

/* Use Case: Verifying if all three elements in a set are even numbers. */
inline bool all_even(int x, int y, int z) {
  return !(x & 1) && !(y & 1) && !(z & 1);
}

/* Use Case: Dynamic verification of sequence homogeneity across vectors. */
template <typename T>
inline bool allEqual(const vector<T>& v) {
  return sz(v) < 2 || adjacent_find(all(v), not_equal_to<T>()) == v.end();
}