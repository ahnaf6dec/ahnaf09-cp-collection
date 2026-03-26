/*
Problem Statement:
You are given an array a of size n and an integer x.
Your task is to count the number of non-empty subarrays
whose sum is exactly equal to x.

Input:
- First line contains two integers n and x (1 ≤ n ≤ 1e5)
- Second line contains n integers a1, a2, ..., an

Output:
- Print a single integer: the number of subarrays with sum x

Constraints:
- 1 ≤ n ≤ 100000
- Elements of the array can be negative, zero, or positive

Note:
- A subarray is a contiguous segment of the array.
- The solution should be efficient (better than O(n²)).
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in.txt", "r", stdin);

  
  int n, x;
  cin >> n >> x;

  vector<int> a(n + 1), pref(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }

  map<int, int> mp;
  ll cnt = 0;

  mp[0] = 1;

  for (int r = 1; r <= n; ++r) {
    cnt += mp[pref[r] - x];
    mp[pref[r]]++;
  }

  cout << cnt << endl;

  return 0;
}
