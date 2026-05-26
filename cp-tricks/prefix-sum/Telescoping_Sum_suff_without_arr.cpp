/*
Main implementation : https://codeforces.com/contest/1709/submission/376106518
=========================================================
            Prefix + Telescoping Sum Trick
=========================================================

For adjacent values:

a[i] - a[i-1]
=
max(0, a[i]-a[i-1])
-
max(0, a[i-1]-a[i])

Summing over a range telescopes:

Σ(a[i]-a[i-1]) = a[r] - a[l]

So:

UP - DOWN = a[r] - a[l]

=> UP = a[r] - a[l] + DOWN

If pref stores:
pref[i] = Σ max(0, a[i-1]-a[i])

Then:

Forward  (l < r):
ans = pref[r] - pref[l]

Backward (l > r):
ans = a[l] - a[r] + pref[l] - pref[r]

Complexity:
Build  : O(n)
Query  : O(1)

=========================================================
*/

void Solve() {
  int n, q;
  cin >> n >> q;

  vector<ll> a(n + 1), pref(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // build downward cost prefix
  for (int i = 2; i <= n; ++i) {
    pref[i] = pref[i - 1] + max(0LL, a[i - 1] - a[i]);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    // moving right
    if (l < r) {
      cout << pref[r] - pref[l] << endl;
    }

    // moving left
    else {
      cout << a[l] - a[r] + pref[l] - pref[r] << endl;
    }
  }
}
