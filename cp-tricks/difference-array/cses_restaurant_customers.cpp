// https://cses.fi/problemset/task/1619
// concept : map, diff array, prefix sum
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<long long, int> diff;

  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;

    diff[a]++;  // customer enters
    diff[b]--;  // customer leaves
  }

  int current = 0;
  int ans = 0;

  // prefix sum over sorted times
  for (auto &it : diff) {
    current += it.second;
    ans = max(ans, current);
  }

  cout << ans << endl;
  return 0;
}
