#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  cin.tie(0)->sync_with_stdio(0);


  // Main implementation of suffix and prefix sum with condition
  // i am using 1 based index prefix sum here.
  // main sol here -> https://codeforces.com/contest/1709/submission/376102485
  vector<ll> a(n + 1), pref(n + 1, 0), suff(n + 1, 0);
 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
 
  for (int i = 2; i <= n; ++i) {
    pref[i] = pref[i - 1] + max(0LL, a[i - 1] - a[i]);
    suff[i] = suff[i - 1] + max(0LL, a[i] - a[i - 1]);
  }
  
  return 0;
}
