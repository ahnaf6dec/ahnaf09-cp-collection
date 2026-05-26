// main implementation here -> https://codeforces.com/contest/1709/submission/376102485
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    /*
    =========================================================
        PREFIX + SUFFIX (DIFFERENCE COST) TECHNIQUE
    =========================================================

    Idea:
    We preprocess an array to answer movement cost queries
    between any two indices in O(1).

    Define:

    forward cost (downward movement):
        cost[i] = max(0, a[i-1] - a[i])

    backward cost (upward movement):
        cost[i] = max(0, a[i] - a[i-1])

    Then build:

    pref[i] = sum of forward costs up to i
    suff[i] = sum of backward costs up to i

    =========================================================
    KEY INTUITION (TELLESCOPING TRICK)
    =========================================================

    For any adjacent pair:
        a[i] - a[i-1]
        = max(0, a[i] - a[i-1]) - max(0, a[i-1] - a[i])

    Summing over a segment telescopes:

        sum(a[i] - a[i-1]) = a[r] - a[l]

    So we get:

        UP - DOWN = a[r] - a[l]

    => UP = a[r] - a[l] + DOWN

    =========================================================
    QUERY RESULT
    =========================================================

    If l < r:
        answer = pref[r] - pref[l]

    If l > r:
        answer = a[l] - a[r] + pref[l] - pref[r]

    =========================================================
    COMPLEXITY
    =========================================================
    Preprocessing: O(n)
    Query:         O(1)
    =========================================================
    */

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1), pref(n + 1, 0), suff(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; ++i) {
        pref[i] = pref[i - 1] + max(0LL, a[i - 1] - a[i]);
        suff[i] = suff[i - 1] + max(0LL, a[i] - a[i - 1]);
    }

    // pref  -> downward cost (right move cost)
    // suff  -> upward cost (left move cost)

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l < r) {
            cout << pref[r] - pref[l] << endl;
        } else {
           cout << suff[l] - suff[r] << endl;
        }
    }

    return 0;
}
