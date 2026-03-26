/*
      _       _                     __   ___
  __ _| |__   | |__    _ __    ___  / _| / _ \
 / _` | '_ \  | '_ \  | '_ \  / _ \| |_ | (_) |
| (_| | | | | | | | | | | | ||  __/|  _| \__, |
 \__,_|_| |_| |_| |_| |_| |_| \___||_|     /_/

        Author : ahnaf09
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

/*
PREFIX SUM (1-Based Indexing) — BASIC CONCEPT

1) pre[i] stores the sum of array elements from index 1 to i.
   pre[i] = pre[i-1] + a[i]

2) pre[0] = 0 is mandatory.
   It allows safe calculation when l = 1.

3) Range sum from l to r can be obtained in O(1):
   sum(l, r) = pre[r] - pre[l-1]

4) Why it works:
   pre[r]  = sum(1 -> r)
   pre[l-1]= sum(1 -> l-1)
   Subtracting removes extra part, leaving sum(l -> r)

5) Time Complexity:
   Build prefix sum: O(n)
   Each query: O(1)

6) Use cases:
   - Fast range sum queries
   - Frequency accumulation
   - Many CP & math problems
*/


void Solve() {
  int n;
  cin >> n;

  vector<ll> a(n + 1), pre(n + 1);
  pre[0] = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i]; // formula
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << endl;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //   freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  clock_t start = clock();
#endif

  int T = 1;
  // int T;
  // cin >> T;

  for (int tc = 1; tc <= T; tc++) {
#ifndef ONLINE_JUDGE
    cout << "Case #" << tc << ": ";
#endif

    Solve();
  }

#ifndef ONLINE_JUDGE
  cerr << "Time : " << fixed << setprecision(3)
       << (double)(clock() - start) / CLOCKS_PER_SEC << " sec" << endl;
#endif

  return 0;
}
