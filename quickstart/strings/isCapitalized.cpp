#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

inline bool isCapitalized(const string& s) {
  int n = s.size();
  if (!n) return false;

  // first char must be uppercase
  if ((unsigned)(s[0] - 'A') > 25) return false;

  // rest must be lowercase
  for (int i = 1; i < n; ++i)
    if ((unsigned)(s[i] - 'a') > 25) return false;

  return true;
}
