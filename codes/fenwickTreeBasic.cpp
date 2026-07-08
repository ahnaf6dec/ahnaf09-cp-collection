/*
================ FENWICK TREE / BIT ================
Purpose:
- Dynamic prefix sum data structure
- Supports:
    1. Point Update
    2. Prefix Sum Query

Complexity:
- Update : O(log N)
- Query  : O(log N)
- Memory : O(N)

Idea:
- Stores partial sums instead of full prefix sums.
- Each node i stores a range of size:
        lowbit(i) = i & -i

Range stored by i:
        [i - lowbit(i) + 1 ... i]

Operations:
- Update moves upward:
        i += i & -i

- Query moves downward:
        i -= i & -i

Why i & -i?
- Extracts the lowest set bit of i.

Range Sum:
        sum(l,r) = prefix(r) - prefix(l-1)

Indexing:
- Usually 1-based for simpler bit operations.

Applications:
- Prefix sums
- Frequency counting
- Inversion counting
- Coordinate compression
- Offline queries

==================================================
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
  int n;
  vector<ll> bit;
  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void add(int i, ll val) {
    while (i <= n) {
      bit[i] += val;
      i += i & -i;
    }
  }

  ll sum(int i) {
    ll res = 0;
    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }

  ll rangeSum(int l, int r) { return sum(r) - sum(l - 1); }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Fenwick fw(10);
  fw.add(3, 5);
  fw.add(7, 2);

  cout << fw.sum(7) << endl;
  cout << fw.rangeSum(3, 7) << endl;

  return 0;
}
