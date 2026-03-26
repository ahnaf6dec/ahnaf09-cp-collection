#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace StrUtil {

/* =====================================================
   ASCII FAST CHAR OPS (NO LOCALE)
   ===================================================== */

/*
 * Convert single char to uppercase (ASCII only)
 * Usage: char c2 = toUpper(c1);
 */
inline char toUpper(char c) { return (c >= 'a' && c <= 'z') ? (c - 32) : c; }

/*
 * Convert single char to lowercase (ASCII only)
 * Usage: char c2 = toLower(c1);
 */
inline char toLower(char c) { return (c >= 'A' && c <= 'Z') ? (c + 32) : c; }

/*
 * Check if char is lowercase (a-z)
 */
inline bool isLower(char c) { return (c >= 'a' && c <= 'z'); }

/*
 * Check if char is uppercase (A-Z)
 */
inline bool isUpper(char c) { return (c >= 'A' && c <= 'Z'); }

/*
 * Check if char is a digit (0-9)
 */
inline bool isDigit(char c) { return (c >= '0' && c <= '9'); }

/*
 * Check if char is alphabetic (A-Z or a-z)
 */
inline bool isAlpha(char c) { return isLower(c) || isUpper(c); }

/*
 * Check if char is alphanumeric (A-Z, a-z, 0-9)
 */
inline bool isAlnum(char c) { return isAlpha(c) || isDigit(c); }

/* =====================================================
   DESTRUCTIVE CASE TRANSFORMATIONS
   ===================================================== */

/*
 * Convert entire string to uppercase (modifies input)
 */
inline void makeUpper(string &s) {
  for (char &c : s) c = toUpper(c);
}

/*
 * Convert entire string to lowercase (modifies input)
 */
inline void makeLower(string &s) {
  for (char &c : s) c = toLower(c);
}

/*
 * Capitalize string: first char uppercase, rest lowercase (modifies input)
 */
inline void capitalize(string &s) {
  if (s.empty()) return;
  s[0] = toUpper(s[0]);
  for (int i = 1; i < (int)s.size(); ++i) s[i] = toLower(s[i]);
}

/*
 * Check if string is capitalized (first upper, rest lower)
 */
inline bool isCapitalized(const string &s) {
  if (s.empty() || !isUpper(s[0])) return false;
  for (int i = 1; i < (int)s.size(); ++i)
    if (!isLower(s[i])) return false;
  return true;
}

/* =====================================================
   NON-DESTRUCTIVE CASE TRANSFORMATIONS
   ===================================================== */

/*
 * Return new string converted fully to uppercase
 */
inline string makeUpperStr(const string &s) {
  string res;
  res.reserve(s.size());
  for (char c : s) res.push_back(toUpper(c));
  return res;
}

/*
 * Return new string converted fully to lowercase
 */
inline string makeLowerStr(const string &s) {
  string res;
  res.reserve(s.size());
  for (char c : s) res.push_back(toLower(c));
  return res;
}

/*
 * Return new string capitalized (first upper, rest lower)
 */
inline string capitalizeStr(const string &s) {
  if (s.empty()) return "";
  string res;
  res.reserve(s.size());
  res.push_back(toUpper(s[0]));
  for (int i = 1; i < (int)s.size(); ++i) res.push_back(toLower(s[i]));
  return res;
}

/*
 * Return reversed copy of the string
 */
inline string reverseStr(const string &s) {
  return string(s.rbegin(), s.rend());
}

/* =====================================================
   SUBSTRING / SLICE
   ===================================================== */

/*
 * Return substring from index l to r inclusive (safe)
 */
inline string slice(const string &s, int l, int r) {
  if (l < 0) l = 0;
  if (r >= (int)s.size()) r = s.size() - 1;
  if (l > r) return "";
  return string(s.begin() + l, s.begin() + r + 1);
}

/*
 * Return substring starting at start with length len (safe)
 */
inline string sliceLen(const string &s, int start, int len) {
  if (start < 0 || start >= (int)s.size() || len <= 0) return "";
  return string(s.begin() + start, s.begin() + min(start + len, (int)s.size()));
}

/* =====================================================
   STRING BUILDERS
   ===================================================== */

/*
 * Repeat single char c, k times
 */
inline string repeat(char c, int k) { return string(k, c); }

/*
 * Repeat entire string s, k times
 */
inline string repeat(const string &s, int k) {
  string r;
  r.reserve(s.size() * k);
  while (k--) r += s;
  return r;
}

/*
 * Alias for repeat string
 */
inline string repeatStr(const string &s, int k) { return repeat(s, k); }

/* =====================================================
   STRING CHECKERS
   ===================================================== */

/*
 * Check if all characters are lowercase
 */
inline bool isAllLower(const string &s) {
  for (char c : s)
    if (!isLower(c)) return false;
  return true;
}

/*
 * Check if all characters are uppercase
 */
inline bool isAllUpper(const string &s) {
  for (char c : s)
    if (!isUpper(c)) return false;
  return true;
}

/*
 * Check if string contains only digits
 */
inline bool isNumeric(const string &s) {
  if (s.empty()) return false;
  for (char c : s)
    if (!isDigit(c)) return false;
  return true;
}

/*
 * Check if string is a palindrome
 */
inline bool isPalindrome(const string &s) {
  int l = 0, r = s.size() - 1;
  while (l < r)
    if (s[l++] != s[r--]) return false;
  return true;
}

/* =====================================================
   TRIM / ERASE
   ===================================================== */

/*
 * Remove leading spaces
 */
inline void ltrim(string &s) {
  int i = 0;
  while (i < (int)s.size() && s[i] == ' ') i++;
  s.erase(0, i);
}

/*
 * Remove trailing spaces
 */
inline void rtrim(string &s) {
  int i = s.size() - 1;
  while (i >= 0 && s[i] == ' ') i--;
  s.erase(i + 1);
}

/*
 * Remove leading and trailing spaces
 */
inline void trim(string &s) {
  ltrim(s);
  rtrim(s);
}

/*
 * Remove all occurrences of character c
 */
inline void eraseChar(string &s, char c) {
  s.erase(remove(s.begin(), s.end(), c), s.end());
}

/* =====================================================
   SPLIT & JOIN
   ===================================================== */

/*
 * Split string by delimiter into vector of strings
 */
inline vector<string> split(const string &s, char delim) {
  vector<string> res;
  string cur;
  for (char c : s) {
    if (c == delim) {
      if (!cur.empty()) res.push_back(cur);
      cur.clear();
    } else
      cur.push_back(c);
  }
  if (!cur.empty()) res.push_back(cur);
  return res;
}

/*
 * Join vector of strings with separator
 */
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

/* =====================================================
   RANDOM STRING GENERATOR
   ===================================================== */

/*
 * Generate random string of given length
 * Parameters: lower, upper, digit, special
 */
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

/* =====================================================
   STRING ↔ NUMBER
   ===================================================== */

/*
 * Convert numeric string to long long
 */
inline long long toLL(const string &s) {
  long long x = 0;
  for (char c : s) x = x * 10 + (c - '0');
  return x;
}

/*
 * Convert numeric string to int
 */
inline int toInt(const string &s) {
  int x = 0;
  for (char c : s) x = x * 10 + (c - '0');
  return x;
}

/* =====================================================
   FIND & REPLACE
   ===================================================== */

/*
 * Replace all occurrences of char a with b in string
 */
inline void replaceAll(string &s, char a, char b) {
  for (char &c : s)
    if (c == a) c = b;
}

/*
 * Check if string starts with prefix p
 */
inline bool startsWith(const string &s, const string &p) {
  return s.size() >= p.size() && equal(p.begin(), p.end(), s.begin());
}

/*
 * Check if string ends with suffix p
 */
inline bool endsWith(const string &s, const string &p) {
  return s.size() >= p.size() && equal(p.rbegin(), p.rend(), s.rbegin());
}

}  // namespace StrUtil
