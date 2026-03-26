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
#define ll long long
#define endl '\n'

/*
============================================================
1) BRUTE FORCE APPROACH
------------------------------------------------------------
Technique:
- Try all subarrays
- Fix starting index i
- Extend ending index j
- Keep adding and update maximum sum

Time Complexity: O(n^2)
Space Complexity: O(1)

Use Case:
- Learning
- Very small constraints
============================================================
*/
ll maxSubarraySumBrute(const vector<ll>& a) {
  int n = a.size();
  ll ans = LLONG_MIN;

  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      ans = max(ans, sum);
    }
  }
  return ans;
}

/*
============================================================
2) KADANE'S ALGORITHM
------------------------------------------------------------
Technique:
- Maintain running sum
- If running sum becomes negative, reset to 0
- Keep global maximum

Core Idea:
Negative prefix never helps future subarray

Time Complexity: O(n)
Space Complexity: O(1)

Most used in Competitive Programming
============================================================
*/
ll maxSubarraySumKadane(const vector<ll>& a) {
  ll currSum = 0;
  ll maxSum = LLONG_MIN;

  for (ll x : a) {
    currSum += x;
    maxSum = max(maxSum, currSum);

    if (currSum < 0) currSum = 0;
  }
  return maxSum;
}

/*
============================================================
3) PREFIX SUM BASED APPROACH
------------------------------------------------------------
Technique:
- pre[i] = sum of a[0..i]
- Max subarray ending at i =
  pre[i] - minimum prefix before i

Formula:
maxSubarraySum = max(pre[i] - minPrefix)

Time Complexity: O(n)
Space Complexity: O(1)

Kadane and Prefix Sum are mathematically equivalent
============================================================
*/
ll maxSubarraySumPrefix(const vector<ll>& a) {
  ll pre = 0;
  ll minPre = 0;
  ll ans = LLONG_MIN;

  for (ll x : a) {
    pre += x;
    ans = max(ans, pre - minPre);
    minPre = min(minPre, pre);
  }
  return ans;
}

/*
============================================================
Example Usage
============================================================
*/
int main() {
	cin.tie(0)->sync_with_stdio(0);
  vector<ll> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  cout << "Brute Force: " << maxSubarraySumBrute(a) << '\n';
  cout << "Kadane: " << maxSubarraySumKadane(a) << '\n';
  cout << "Prefix Sum: " << maxSubarraySumPrefix(a) << '\n';

  return 0;
}
