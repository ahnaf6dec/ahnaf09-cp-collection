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
