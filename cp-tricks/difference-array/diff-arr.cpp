// this is the raw implementation
/*
------------------------------------------------------------
Problem: Range Update Using Difference Array
------------------------------------------------------------

You are given an integer n representing the size of an array
initially filled with zeros.

You are also given q queries. Each query contains two integers
l and r (1 ≤ l ≤ r ≤ n).

For every query, increase all elements in the range [l, r] by 1.

After processing all queries, output the final array.

------------------------------------------------------------
Input:
- First line: two integers n and q
- Next q lines: two integers l and r

------------------------------------------------------------
Output:
- Print n integers
- The i-th integer is the final value at index i

------------------------------------------------------------
Constraints:
- 1 ≤ n, q ≤ 2×10^5

------------------------------------------------------------
Technique:
- Difference Array
- Prefix Sum

------------------------------------------------------------
Time Complexity:
- O(n + q)

Space Complexity:
- O(n)

------------------------------------------------------------
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  // Difference array (1-based indexing)
  vector<int> diff(n + 2, 0);

  while (q--) {
    int l, r;
    cin >> l >> r;

    diff[l]++;      // start increment at l
    diff[r + 1]--;  // stop increment after r
  }

  // Build the final array using prefix sum
  for (int i = 1; i <= n; ++i) {
    diff[i] += diff[i - 1];
    cout << diff[i] << ' ';
  }

  cout << '\n';

  return 0;
}
