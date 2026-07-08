#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Point Update and Range Query
struct Fenwick {
  int n;
  vector<ll> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  // O(N) build, a should be 1-indexed
  Fenwick(const vector<ll>& a) {
    n = (int)a.size() - 1;
    bit = a;

    for (int i = 1; i <= n; i++) {
      int j = i + (i & -i);
      if (j <= n) bit[j] += bit[i];
    }
  }

  // add val to index i
  // O(log N)
  void add(int i, ll val) {
    while (i <= n) {
      bit[i] += val;
      i += i & -i;
    }
  }

  // prefix sum [1..i]
  // O(log N)
  ll sum(int i) const {
    ll res = 0;

    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }

    return res;
  }

  // range sum [l..r]
  // O(log N)
  ll rangeSum(int l, int r) const { return sum(r) - sum(l - 1); }
};
// Range Update and Range Query
struct RangeFenwickRQ {
  int n;
  Fenwick bit1, bit2;

  RangeFenwickRQ(int n) : n(n), bit1(n), bit2(n) {}

  // internal point update on two BITs
  void add(int idx, ll val) {
    bit1.add(idx, val);
    bit2.add(idx, val * (idx - 1));
  }

  // add val to [l, r]
  void rangeAdd(int l, int r, ll val) {
    add(l, val);
    add(r + 1, -val);
  }

  // sum of [1..idx]
  ll prefixSum(int idx) const { return bit1.sum(idx) * idx - bit2.sum(idx); }

  // sum of [l..r]
  ll rangeSum(int l, int r) const { return prefixSum(r) - prefixSum(l - 1); }
};
// Range Update and Point Query
struct RangeFenwickPQ {
  int n;
  vector<ll> bit;

  RangeFenwickPQ(int n) : n(n), bit(n + 1, 0) {}

  // add value at one point in difference array
  void add(int idx, ll val) {
    while (idx <= n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  // add val to range [l, r]
  void rangeAdd(int l, int r, ll val) {
    add(l, val);
    add(r + 1, -val);
  }

  // get value at index idx
  ll get(int idx) const {
    ll res = 0;

    while (idx > 0) {
      res += bit[idx];
      idx -= idx & -idx;
    }

    return res;
  }
};
// Min of [0,....,r]
struct FenwickMin {
  int n;
  const int INF = 1e9;
  vector<int> bit;
  FenwickMin(int n) : n(n), bit(n, INF) {}
  // a[i] = min(a[i], val)
  void update(int i, int val) {
    while (i < n) {
      bit[i] = min(bit[i], val);
      i = i | (i + 1);
    }
  }
  // minimum of [0 ... r]
  int query(int r) const {
    int ans = INF;

    while (r >= 0) {
      ans = min(ans, bit[r]);
      r = (r & (r + 1)) - 1;
    }

    return ans;
  }
};
// Max of [0,.....r] (Optional)
struct FenwickMax {
  int n;
  const int NEG_INF = -1e9;
  vector<int> bit;

  FenwickMax(int n) : n(n), bit(n, NEG_INF) {}

  // a[i] = max(a[i], val)
  void update(int i, int val) {
    while (i < n) {
      bit[i] = max(bit[i], val);
      i = i | (i + 1);
    }
  }

  // maximum of [0 ... r]
  int query(int r) const {
    int ans = NEG_INF;

    while (r >= 0) {
      ans = max(ans, bit[r]);
      r = (r & (r + 1)) - 1;
    }

    return ans;
  }
};
// 2D array sum on fenwick
struct Fenwick2D {
  int n, m;
  vector<vector<ll>> bit;

  Fenwick2D(int n, int m) : n(n), m(m) {
    bit.assign(n + 1, vector<ll>(m + 1, 0));
  }

  // add val to position (x,y)
  // O(logN * logM)
  void add(int x, int y, ll val) {
    for (; x <= n; x += x & -x) {
      for (int j = y; j <= m; j += j & -j) {
        bit[x][j] += val;
      }
    }
  }

  // prefix sum (1,1) -> (x,y)
  // O(logN * logM)
  ll sum(int x, int y) const {
    ll res = 0;

    for (; x > 0; x -= x & -x) {
      for (int j = y; j > 0; j -= j & -j) {
        res += bit[x][j];
      }
    }

    return res;
  }

  // rectangle sum:
  // (x1,y1) -> (x2,y2)
  // O(logN * logM)
  ll rangeSum(int x1, int y1, int x2, int y2) const {
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
           sum(x1 - 1, y1 - 1);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);

  return 0;
}