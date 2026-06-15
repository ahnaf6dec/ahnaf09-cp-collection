#include <bits/stdc++.h>
using namespace std;

namespace StrUtil {

// -----------------------------------------------------------------------------
// 1. ASCII CHARACTER FAST OPS (NO LOCALE DEPENDENCY)
// -----------------------------------------------------------------------------

/* Use Case: Normalizing a raw character state into uppercase. */
inline char toUpper(char c) { return (c >= 'a' && c <= 'z') ? (c - 32) : c; }

/* Use Case: Normalizing a raw character state into lowercase. */
inline char toLower(char c) { return (c >= 'A' && c <= 'Z') ? (c + 32) : c; }

/* Use Case: Verifying lowercase properties quickly. */
inline bool isLower(char c) { return (c >= 'a' && c <= 'z'); }

/* Use Case: Verifying uppercase properties quickly. */
inline bool isUpper(char c) { return (c >= 'A' && c <= 'Z'); }

/* Use Case: Fast token numeric validation. */
inline bool isDigit(char c) { return (c >= '0' && c <= '9'); }

/* Use Case: Testing alpha formatting configurations. */
inline bool isAlpha(char c) { return isLower(c) || isUpper(c); }

/* Use Case: Clean non-special alphanumeric input screenings. */
inline bool isAlnum(char c) { return isAlpha(c) || isDigit(c); }

// -----------------------------------------------------------------------------
// 2. DESTRUCTIVE CASE MUTATIONS (IN-PLACE ALTERATIONS)
// -----------------------------------------------------------------------------

/* Use Case: Eliminating overhead mutations by capitalizing standard input
 * references. */
inline void makeUpper(string &s) {
  for (char &c : s) c = toUpper(c);
}

/* Use Case: Lowercasing dictionary entries for uniform mapping strategies. */
inline void makeLower(string &s) {
  for (char &c : s) c = toLower(c);
}

/* Use Case: Standardizing title parameters dynamically (Modifies input). */
inline void capitalize(string &s) {
  if (s.empty()) return;
  s[0] = toUpper(s[0]);
  for (int i = 1; i < (int)s.size(); ++i) s[i] = toLower(s[i]);
}

/* Use Case: Hyper-optimized check for title/name formatting constraints. */
inline bool isCapitalized(const string &s) {
  int n = s.size();
  if (!n) return false;
  // Fast unsigned conversion check strategy
  if ((unsigned)(s[0] - 'A') > 25) return false;
  for (int i = 1; i < n; ++i) {
    if ((unsigned)(s[i] - 'a') > 25) return false;
  }
  return true;
}

// -----------------------------------------------------------------------------
// 3. NON-DESTRUCTIVE CASE MUTATIONS (RETURNS NEW INSTANCE)
// -----------------------------------------------------------------------------

/* Use Case: Producing safe capitalized string copies without dropping original
 * contexts. */
inline string makeUpperStr(const string &s) {
  string res;
  res.reserve(s.size());
  for (char c : s) res.push_back(toUpper(c));
  return res;
}

/* Use Case: Creating standard key values for hash map assignments. */
inline string makeLowerStr(const string &s) {
  string res;
  res.reserve(s.size());
  for (char c : s) res.push_back(toLower(c));
  return res;
}

/* Use Case: Text processing output serialization where format matching is
 * forced. */
inline string capitalizeStr(const string &s) {
  if (s.empty()) return "";
  string res;
  res.reserve(s.size());
  res.push_back(toUpper(s[0]));
  for (int i = 1; i < (int)s.size(); ++i) res.push_back(toLower(s[i]));
  return res;
}

/* Use Case: String generation algorithms, suffix arrays, or basic reversal
 * validations. */
inline string reverseStr(const string &s) {
  return string(s.rbegin(), s.rend());
}

// -----------------------------------------------------------------------------
// 4. SLICING & SUBSTRING EXTRACTIONS (OUT-OF-BOUNDS PROTECTED)
// -----------------------------------------------------------------------------

/* Use Case: Safely scanning sliding text segments without risking segmentation
 * faults. */
inline string slice(const string &s, int l, int r) {
  if (l < 0) l = 0;
  if (r >= (int)s.size()) r = s.size() - 1;
  if (l > r) return "";
  return string(s.begin() + l, s.begin() + r + 1);
}

/* Use Case: Fixed length frame analysis across fluctuating data lines. */
inline string sliceLen(const string &s, int start, int len) {
  if (start < 0 || start >= (int)s.size() || len <= 0) return "";
  return string(s.begin() + start, s.begin() + min(start + len, (int)s.size()));
}

// -----------------------------------------------------------------------------
// 5. STRING GENERATORS & BUILDERS
// -----------------------------------------------------------------------------

/* Use Case: Quick alignment padding for custom console tables or outputs. */
inline string repeat(char c, int k) { return string(k, c); }

/* Use Case: Fast grid structure layouts or mathematical pattern strings. */
inline string repeat(const string &s, int k) {
  string r;
  r.reserve(s.size() * k);
  while (k--) r += s;
  return r;
}
inline string repeatStr(const string &s, int k) { return repeat(s, k); }

/* Use Case: Fuzzing algorithms or stress-testing tree parsing boundaries. */
static inline mt19937 rng(
    (uint32_t)chrono::steady_clock::now().time_since_epoch().count());
inline string randomString(int len, bool lower = true, bool upper = true,
                           bool digit = true, bool special = false) {
  static const string L = "abcdefghijklmnopqrstuvwxyz";
  static const string U = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  static const string D = "0123456789";
  static const string S = "!@#$%^&*";
  string pool;
  if (lower) pool += L;
  if (upper) pool += U;
  if (digit) pool += D;
  if (special) pool += S;
  uniform_int_distribution<int> dist(0, pool.size() - 1);
  string res;
  res.reserve(len);
  while (len--) res.push_back(pool[dist(rng)]);
  return res;
}

// -----------------------------------------------------------------------------
// 6. STRUCTURAL VALIDATION CHECKERS
// -----------------------------------------------------------------------------

/* Use Case: Verifying pure case properties across raw token buffers. */
inline bool isAllLower(const string &s) {
  for (char c : s)
    if (!isLower(c)) return false;
  return true;
}

/* Use Case: Asserting specialized acronym codes or structural keys. */
inline bool isAllUpper(const string &s) {
  for (char c : s)
    if (!isUpper(c)) return false;
  return true;
}

/* Use Case: Checking clean digit sequences before using numeric casts. */
inline bool isNumeric(const string &s) {
  if (s.empty()) return false;
  for (char c : s)
    if (!isDigit(c)) return false;
  return true;
}

/* Use Case: Classic interview/competitive string state confirmation. */
inline bool isPalindrome(const string &s) {
  int l = 0, r = (int)s.size() - 1;
  while (l < r)
    if (s[l++] != s[r--]) return false;
  return true;
}

// -----------------------------------------------------------------------------
// 7. TRIMMING & INLINE ERASING
// -----------------------------------------------------------------------------

/* Use Case: Stripping accidental white spaces during reading sequences. */
inline void ltrim(string &s) {
  int i = 0;
  while (i < (int)s.size() && s[i] == ' ') i++;
  s.erase(0, i);
}

/* Use Case: Standard cleaning for file systems line parsers. */
inline void rtrim(string &s) {
  int i = (int)s.size() - 1;
  while (i >= 0 && s[i] == ' ') i--;
  s.erase(i + 1);
}

/* Use Case: Comprehensive wrapping text formatting corrections. */
inline void trim(string &s) {
  ltrim(s);
  rtrim(s);
}

/* Use Case: Completely scrubbing dynamic noise configurations from data
 * streams. */
inline void eraseChar(string &s, char c) {
  s.erase(remove(s.begin(), s.end(), c), s.end());
}

// -----------------------------------------------------------------------------
// 8. SPLIT & JOIN STRING ORCHESTRATIONS
// -----------------------------------------------------------------------------

/* Use Case: Tokenizing command strings or comma-separated value sequences. */
inline vector<string> split(const string &s, char delim) {
  vector<string> res;
  string cur;
  for (char c : s) {
    if (c == delim) {
      if (!cur.empty()) res.push_back(cur);
      cur.clear();
    } else {
      cur.push_back(c);
    }
  }
  if (!cur.empty()) res.push_back(cur);
  return res;
}

/* Use Case: Assembling flat database layouts out of tracked vector listings. */
inline string join(const vector<string> &v, char sep = ' ') {
  string res;
  size_t total = 0;
  for (auto &s : v) total += s.size() + 1;
  res.reserve(total);
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i) res.push_back(sep);
    res += v[i];
  }
  return res;
}

// -----------------------------------------------------------------------------
// 9. PURE NUMERIC CONVERTERS (OVERHEAD-FREE REPLACEMENTS FOR std::stoll)
// -----------------------------------------------------------------------------

/* Use Case: Fast scalar mapping from high-velocity string streams. */
inline long long toLL(const string &s) {
  long long x = 0;
  for (char c : s) x = x * 10 + (c - '0');
  return x;
}

/* Use Case: Fast parsing of small index tags or matrix dimensions. */
inline int toInt(const string &s) {
  int x = 0;
  for (char c : s) x = x * 10 + (c - '0');
  return x;
}

// -----------------------------------------------------------------------------
// 10. ADVANCED FREQUENCY & SUBSEQUENCE ENGINES
// -----------------------------------------------------------------------------

/* Use Case: Substituting single matching elements for uniform display mapping.
 */
inline void replaceAll(string &s, char a, char b) {
  for (char &c : s)
    if (c == a) c = b;
}

/* Use Case: Fast router parsing checks or validation of network pathing
 * strings. */
inline bool startsWith(const string &s, const string &p) {
  return s.size() >= p.size() && equal(p.begin(), p.end(), s.begin());
}

/* Use Case: Verifying document types or trailing structural attributes. */
inline bool endsWith(const string &s, const string &p) {
  return s.size() >= p.size() && equal(p.rbegin(), p.rend(), s.rbegin());
}

/* Use Case: Locating modal elements or dominant characters inside input queues.
 */
pair<char, int> maxFreq(const string &s) {
  int f[256] = {}, m = 0;
  char r = 0;
  for (unsigned char c : s)
    if (++f[c] > m) m = f[r = c];
  return {r, m};
}

/* Use Case: Locating rare anomaly keys within structural text feeds. */
pair<char, int> minFreq(const string &s) {
  int f[256] = {}, m = 1e9;
  char r = 0;
  for (unsigned char c : s) f[c]++;
  for (unsigned char c : s)
    if (f[c] < m) m = f[r = c];
  return {r, m};
}

/* Use Case: Substring similarity algorithms or structural analysis routines. */
auto findSub(string_view s) {
  if (s.empty()) return pair<string, string>{"", ""};
  int n = s.length(), i = n, j = n;
  vector dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      dp[i][j] = (s[i - 1] == s[j - 1] && i != j)
                     ? dp[i - 1][j - 1] + 1
                     : max(dp[i - 1][j], dp[i][j - 1]);
  string l;
  l.reserve(dp[n][n]);
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j - 1] + 1 && s[i - 1] == s[j - 1] && i != j) {
      l += s[i - 1];
      --i;
      --j;
    } else if (dp[i][j] == dp[i - 1][j])
      --i;
    else
      --j;
  }
  reverse(l.begin(), l.end());
  return pair{l, string(1, s[0])};
}

/* Use Case: Finding the Minimum Excluded character (MEX) in a string using
 * bitwise profiles. */
char getMEX(const string &s) {
  uint32_t m = 0;
  for (char c : s)
    if (c >= 'a' && c <= 'z') m |= (1U << (c - 'a'));
  return (~m & 0x3FFFFFF) ? 'a' + __builtin_ctz(~m & 0x3FFFFFF) : '\0';
}

}  // namespace StrUtil