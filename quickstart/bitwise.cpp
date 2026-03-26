// bitmask related shortcut
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

/*--------------------------------------------------------------
 | Helpful Macros
 --------------------------------------------------------------*/
#define setbit(x, i) ((x) | (1LL << (i)))     // set i-th bit
#define clearbit(x, i) ((x) & ~(1LL << (i)))  // clear i-th bit
#define flipbit(x, i) ((x) ^ (1LL << (i)))    // toggle i-th bit
#define checkbit(x, i) (((x) >> (i)) & 1LL)   // check i-th bit
#define lowestbit(x) ((x) & -(x))             // extract lowest set bit
#define allbits(x) ((1ULL << (x)) - 1)        // mask of x bits set

// MoRe Collections if need
// bits
#define SET_BIT(n, k) ((n) | (1LL << (k)))
#define CLEAR_BIT(n, k) ((n) & ~(1LL << (k)))
#define TOGGLE_BIT(n, k) ((n) ^ (1LL << (k)))
#define TOGGLE_ALL_BITS(n) (~(n))
#define TOGGLE_BIT_CHAR(c) ((c) == '0' ? '1' : '0')
#define TOGGLE_ALL_BITS_STR(s) \
  for (char &c : s) c = (c == '0' ? '1' : '0')
#define CHECK_BIT(n, k) (((n) >> (k)) & 1LL)
#define LSB(x) ((x) & -(x))
#define MSB(x) (63 - __builtin_clzll(x))
#define BIT_COUNT(x) (__builtin_popcountll(x))
#define BIT_LENGTH(x) (64 - __builtin_clzll(x))
#define IS_POWER_OF_TWO(x) ((x) && !((x) & ((x) - 1)))
#define ALL_BITS_SET(n) ((1LL << (n)) - 1)
#define IS_SUBMASK(a, b) (((a) & (b)) == (a))

/*--------------------------------------------------------------
 | Bitwise Helper Functions
 --------------------------------------------------------------*/

// Count set bits (Brian Kernighan’s Algorithm)
int countBits(ll x) {
  int cnt = 0;
  while (x) {
    x &= (x - 1);
    cnt++;
  }
  return cnt;
}

// Built-in bit count\int popcount(ll x) { return __builtin_popcountll(x); }

// Position of lowest set bit (1-indexed), 0 if none
int lowbitPos(ll x) {
  if (!x) return 0;
  return __builtin_ctzll(x) + 1;
}

// Position of highest set bit (1-indexed), 0 if none
int highbitPos(ll x) {
  if (!x) return 0;
  return 64 - __builtin_clzll(x);
}

// Check if number is power of two
bool isPowerOfTwo(ll x) { return x > 0 && (x & (x - 1)) == 0; }

// Next power of two >= x
ll nextPowerOfTwo(ll x) {
  if (x <= 0) return 1;
  return 1LL << (64 - __builtin_clzll(x - 1));
}

// XOR of all numbers from 0 to n
ll xorUpto(ll n) {
  switch (n & 3) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
    default:
      return 0;
  }
}

// Fast parity (1 if odd set bits, 0 if even)
int parity(ll x) { return __builtin_parityll(x); }

// Reverse bits in 64-bit integer
ull reverseBits(ull x) {
  ull res = 0;
  for (int i = 0; i < 64; i++) {
    res = (res << 1) | (x & 1);
    x >>= 1;
  }
  return res;
}

// Rotate left
ull rotl(ull x, int k) { return (x << k) | (x >> (64 - k)); }

// Rotate right
ull rotr(ull x, int k) { return (x >> k) | (x << (64 - k)); }

// Generate all submasks of mask
vector<int> submasks(int mask) {
  vector<int> res;
  for (int sub = mask;; sub = (sub - 1) & mask) {
    res.push_back(sub);
    if (!sub) break;
  }
  return res;
}

// Gray code conversion
int binaryToGray(int num) { return num ^ (num >> 1); }
int grayToBinary(int gray) {
  int num = gray;
  while (gray >>= 1) num ^= gray;
  return num;
}

// Compute mask with only highest set bit
ll highestOneBit(ll x) {
  if (x == 0) return 0;
  return 1LL << (63 - __builtin_clzll(x));
}

// Check if two numbers have opposite signs
bool oppositeSigns(ll a, ll b) { return (a ^ b) < 0; }

// Multiply by power of two
ll mulPow2(ll x, int k) { return x << k; }

// Divide by power of two (floor for positive numbers)
ll divPow2(ll x, int k) { return x >> k; }

// Modulo by power of two
ll modPow2(ll x, int k) { return x & ((1LL << k) - 1); }

// Count leading zeros
int clz(ll x) { return __builtin_clzll(x); }

// Count trailing zeros
int ctz(ll x) { return __builtin_ctzll(x); }

// Hamming distance between two numbers
int hammingDist(ll a, ll b) { return __builtin_popcountll(a ^ b); }

// Iterate over all subsets of size k from n elements using bitmask
vector<int> kSubsets(int n, int k) {
  vector<int> res;
  int comb = (1 << k) - 1;
  while (comb < (1 << n)) {
    res.push_back(comb);
    int x = comb & -comb;
    int y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }
  return res;
}

// Generate all subsets of n elements
vector<int> allSubsets(int n) {
  vector<int> res;
  for (int mask = 0; mask < (1 << n); mask++) res.push_back(mask);
  return res;
}

// print binary
void coder(void) {
  string s = "10";
  int x = 0;
  for (char c : s) x = (x << 1) | (c - '0');
}

// deci to bin
void print_decimal_to_binary(long long n) {
  if (n == 0) {
    cout << 0;
    return;
  }

  string s;
  while (n > 0) {
    s.push_back(char('0' + (n & 1)));
    n >>= 1;
  }
  reverse(s.begin(), s.end());
  cout << s;
}
// Binary to Decimal
void print_binary_to_decimal(const string &b) {
  long long val = 0;
  for (char c : b) {
    val = (val << 1) + (c - '0');
  }
  cout << val;
}

// example
/*
    long long x = 23;
    string b = "10111";

    print_decimal_to_binary(x);   // output: 10111
    cout << "\n";

    print_binary_to_decimal(b);   // output: 23
*/