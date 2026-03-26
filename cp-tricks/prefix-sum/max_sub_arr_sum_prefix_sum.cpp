/*
Problem Statement: Maximum Subarray Sum (Prefix Sum)

Story:
A student is tracking their daily study productivity over n days.
Each day’s productivity can be positive (good progress) or negative
(bad or wasted time). The student wants to find a continuous range
of days during which their total productivity was the highest.

Your task is to help the student determine the maximum possible
sum of any non-empty contiguous subarray.

Formal Description:
You are given an array a of size n.
Find the maximum sum of any non-empty subarray.

Input:
- First line contains an integer n (1 ≤ n ≤ 1e5)
- Second line contains n integers a1, a2, ..., an

Output:
- Print a single integer: the maximum subarray sum

Constraints:
- 1 ≤ n ≤ 100000
- Array elements may be negative, zero, or positive

Note:
- A subarray is a contiguous segment of the array.
- Prefix sums can be used where:
  sum(l..r) = pre[r] - pre[l-1]
- An efficient O(n) or O(n log n) solution is expected.
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> pf(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    pf[i] = pf[i - 1] + a[i];
  }

  int ans = LLONG_MIN;  // Handle first element (non-empty subarray)
  int mn = 0;      // Minimum prefix sum seen so far

  for (int r = 1; r <= n; ++r) {
    ans = max(ans, pf[r] - mn);  // Max subarray ending at r
    mn = min(mn, pf[r]);         // Update minimum prefix sum
  }

  cout << ans << endl;
  // return 0;
}
