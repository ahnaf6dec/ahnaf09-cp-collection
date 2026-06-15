#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace HashUtil {

// -------- CONFIGURATION & MACROS --------
#define sz(x) ((int)(x).size())
using ll = long long;

const int MAXA = 1e5 + 5;  // Adjust according to data range constraints
int freq_arr[MAXA];

// -----------------------------------------------------------------------------
// 1. CORE STRUCTURES & CUSTOM ANTI-HACK HASHING
// -----------------------------------------------------------------------------

/* * Custom splitmix64 hash function to prevent O(N^2) malicious hash collisions
 * on Codeforces unordered maps/sets.
 */
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

// Safe anti-hack replacements for unordered standard library containers
template <typename K, typename V>
using safe_map = unordered_map<K, V, custom_hash>;

template <typename T>
using safe_set = unordered_set<T, custom_hash>;

// -----------------------------------------------------------------------------
// 2. FREQUENCY COLLECTORS
// -----------------------------------------------------------------------------

/* Use Case: High-speed frequency count when values fit comfortably within MAXA.
 */
void use_frequency_array(const vector<int>& a) {
  // Zero out only the necessary range if maximum values are known for optimal
  // speed
  memset(freq_arr, 0, sizeof(freq_arr));
  for (int x : a) {
    if (x >= 0 && x < MAXA) freq_arr[x]++;
  }
}

/* Use Case: Gathering frequencies of arbitrary integers without collision
 * exploits. */
safe_map<int, int> get_freq_map(const vector<int>& a) {
  safe_map<int, int> mp;
  mp.reserve(a.size() * 2);
  mp.max_load_factor(0.25);
  for (int x : a) mp[x]++;
  return mp;
}

/* Use Case: Standardizing frequencies of lowercase alphabetical characters. */
vector<int> char_frequency(const string& s) {
  vector<int> cnt(26, 0);
  for (char c : s) cnt[c - 'a']++;
  return cnt;
}

// -----------------------------------------------------------------------------
// 3. COMMON COMPETITIVE CHECKING PATTERNS
// -----------------------------------------------------------------------------

/* Use Case: Confirming if an entire array collection contains distinct values.
 */
bool all_unique(const vector<int>& a) {
  safe_set<int> st;
  for (int x : a) {
    if (st.count(x)) return false;
    st.insert(x);
  }
  return true;
}

/* Use Case: Finding the dominant value/mode inside a sequence. */
int max_frequency_element(const vector<int>& a) {
  safe_map<int, int> mp;
  int mx = 0, val = -1;
  for (int x : a) {
    if (++mp[x] > mx) {
      mx = mp[x];
      val = x;
    }
  }
  return val;
}

/* Use Case: Quick screening for target occurrence limits. */
bool appears_at_least_k(const vector<int>& a, int k) {
  safe_map<int, int> mp;
  for (int x : a) {
    if (++mp[x] >= k) return true;
  }
  return false;
}

// -----------------------------------------------------------------------------
// 4. ADVANCED HASHING UTILITIES
// -----------------------------------------------------------------------------

/* Use Case: Counting pairs (i < j) such that a[i] == a[j]. */
ll count_equal_pairs(const vector<int>& a) {
  safe_map<int, ll> mp;
  ll ans = 0;
  for (int x : a) {
    ans += mp[x];
    mp[x]++;
  }
  return ans;
}

/* Use Case: Mapping large value ranges down to [0, N-1] indices (Coordinate
 * Compression). */
vector<int> compress(vector<int> a) {
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int& x : a) {
    x = lower_bound(b.begin(), b.end(), x) - b.begin();
  }
  return a;
}

/* Use Case: Verification if two data sequences represent structural
 * permutations (Anagrams). */
bool same_frequency(const vector<int>& a, const vector<int>& b) {
  if (a.size() != b.size()) return false;
  safe_map<int, int> mp = get_freq_map(a);
  for (int x : b) {
    if (--mp[x] < 0) return false;
  }
  return true;
}

// -----------------------------------------------------------------------------
// 5. PREFIX SUBARRAY AGGREGATIONS
// -----------------------------------------------------------------------------

/* Use Case: Counting the total number of continuous segments that sum to K. */
ll subarray_sum_k(const vector<int>& a, int k) {
  safe_map<ll, ll> mp;
  mp[0] = 1;
  ll sum = 0, ans = 0;
  for (int x : a) {
    sum += x;
    if (mp.count(sum - k)) ans += mp[sum - k];
    mp[sum]++;
  }
  return ans;
}

/* Use Case: Finding the longest span of a continuous segment matching sum
 * target K. */
int longest_subarray_sum_k(const vector<int>& a, int k) {
  safe_map<ll, int> first;
  ll sum = 0;
  int ans = 0;
  for (int i = 0; i < sz(a); i++) {
    sum += a[i];
    if (sum == k) ans = i + 1;
    if (!first.count(sum)) first[sum] = i;
    if (first.count(sum - k)) {
      ans = max(ans, i - first[sum - k]);
    }
  }
  return ans;
}

}  // namespace HashUtil