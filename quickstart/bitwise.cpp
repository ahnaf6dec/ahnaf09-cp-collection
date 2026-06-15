
#include <bits/stdc++.h>
using namespace std;

namespace BitUtil {

using ll = long long;
using ull = unsigned long long;

// -----------------------------------------------------------------------------
// 1. CORE BITWISE SHORTHAND MACROS
// -----------------------------------------------------------------------------
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define SETBIT(x, i) ((x) | (1LL << (i)))
#define CLEARBIT(x, i) ((x) & ~(1LL << (i)))
#define FLIPBIT(x, i) ((x) ^ (1LL << (i)))
#define LSB(x) ((x) & -(x))

#define MSB(x) (63 - __builtin_clzll(x))
#define BIT_COUNT(x) (__builtin_popcountll(x))
#define BIT_LENGTH(x) (64 - __builtin_clzll(x))

#define ALL_BITS_SET(n) ((1LL << (n)) - 1)
#define IS_POWER_OF_TWO(x) ((x) && !((x) & ((x) - 1)))
#define IS_SUBMASK(sub, mask) (((sub) & (mask)) == (sub))

#define TOGGLE_ALL_BITS(n) (~(n))
#define TOGGLE_BIT_CHAR(c) ((c) == '0' ? '1' : '0')

/* Use Case: Inverting binary configurations stored as flat text strings. */
inline void toggle_all_bits_str(string &s) {
    for (char &c : s) c = (c == '0' ? '1' : '0');
}


// -----------------------------------------------------------------------------
// 2. INTRINSIC PROPERTIES & BIT COUNTERS
// -----------------------------------------------------------------------------

/* Use Case: High-performance population count wrapper. */
inline int popcount(ll x) { return __builtin_popcountll(x); }

/* Use Case: Alternative bit counter using Brian Kernighan’s algorithm. */
inline int countBitsKernel(ll x) {
    int cnt = 0; while (x) { x &= (x - 1); cnt++; } return cnt;
}

/* Use Case: Finding the 1-indexed position of the lowest set bit (0 if none). */
inline int lowbitPos(ll x) { return x ? __builtin_ctzll(x) + 1 : 0; }

/* Use Case: Finding the 1-indexed position of the highest set bit (0 if none). */
inline int highbitPos(ll x) { return x ? 64 - __builtin_clzll(x) : 0; }

/* Use Case: Finding the lowest power of two value greater than or equal to X. */
inline ll nextPowerOfTwo(ll x) {
    if (x <= 0) return 1;
    return 1LL << (64 - __builtin_clzll(x - 1));
}

/* Use Case: Calculating structural variance in message data or network frames. */
// It returns (1) if the number of 1s is [odd], and (0) if the number of 1s is [even].
inline int parity(ll x) { return __builtin_parityll(x); } 

inline int clz(ll x) { return __builtin_clzll(x); }
inline int ctz(ll x) { return __builtin_ctzll(x); }

/* Use Case: Comparing total mismatch counts across state vectors. */
inline int hammingDist(ll a, ll b) { return __builtin_popcountll(a ^ b); }

/* Use Case: Fast inversion of 64-bit integer values. */
inline ull reverseBits(ull x) {
    ull res = 0;
    for (int i = 0; i < 64; i++) { res = (res << 1) | (x & 1); x >>= 1; }
    return res;
}

/* Use Case: Circular bitwise operations inside cryptography or hashing logic. */
inline ull rotl(ull x, int k) { return (x << k) | (x >> (64 - k)); }
inline ull rotr(ull x, int k) { return (x >> k) | (x << (64 - k)); }


// -----------------------------------------------------------------------------
// 3. PREFIX PROPERTIES & ALGEBRAIC TRICKS
// -----------------------------------------------------------------------------

/* Use Case: Computing the prefix XOR sum from 0 up to N in O(1) time complexity. */
inline ll xorUpto(ll n) {
    switch (n & 3) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}

/* Use Case: Minimizing bit state mutations between consecutive integer steps. */
inline int binaryToGray(int num) { return num ^ (num >> 1); }
inline int grayToBinary(int gray) {
    int num = gray; while (gray >>= 1) num ^= gray; return num;
}

/* Use Case: Isolating the single highest active bit mask. */
inline ll highestOneBit(ll x) { return x ? 1LL << (63 - __builtin_clzll(x)) : 0; }

/* Use Case: Fast sign mismatch checking without risking conditional branch misses. */
inline bool oppositeSigns(ll a, ll b) { return (a ^ b) < 0; }

/* Use Case: Speed-optimized shifting operations for power-of-two relations. */
inline ll mulPow2(ll x, int k) { return x << k; }
inline ll divPow2(ll x, int k) { return x >> k; }
inline ll modPow2(ll x, int k) { return x & ((1LL << k) - 1); }


// -----------------------------------------------------------------------------
// 4. MASK & SUBSET ITERATION GENERATORS
// -----------------------------------------------------------------------------

/* Use Case: Efficiently looping through all submasks of a bitwise state profile. */
inline vector<int> submasks(int mask) {
    vector<int> res;
    for (int sub = mask;; sub = (sub - 1) & mask) {
        res.push_back(sub); if (!sub) break;
    }
    return res;
}

/* Use Case: Generating every valid mask combinations up to space boundary size N. */
inline vector<int> allSubsets(int n) {
    vector<int> res; res.reserve(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) res.push_back(mask);
    return res;
}

/* Use Case: Gosper's Hack - Iterates over all subsets of size K out of N elements. */
inline vector<int> kSubsets(int n, int k) {
    vector<int> res; if (k > n || k < 0) return res;
    int comb = (1 << k) - 1;
    while (comb < (1 << n)) {
        res.push_back(comb);
        int x = comb & -comb; int y = comb + x;
        comb = (((comb & ~y) / x) >> 1) | y;
    }
    return res;
}


// -----------------------------------------------------------------------------
// 5. STRING ↔ BINARY CONVERSION ENGINES
// -----------------------------------------------------------------------------

/* Use Case: Converting base-10 values into raw printable binary strings. */
inline string toBinaryStr(ll n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) { s.push_back((n & 1) ? '1' : '0'); n >>= 1; }
    reverse(s.begin(), s.end());
    return s;
}

/* Use Case: Compiling raw text binary arrays back into 64-bit scalar storage variables. */
inline ll toDecimal(const string &b) {
    ll val = 0;
    for (char c : b) { val = (val << 1) | (c - '0'); }
    return val;
}

} // namespace BitUtil