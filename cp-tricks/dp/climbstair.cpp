#include <bits/stdc++.h>
using namespace std;

// O(2^n)
int climbStairsBrute(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return climbStairsBrute(n - 1) + climbStairsBrute(n - 2);
}

// O(n) - Top Down DP (Memoization)
int solveMemo(int step, vector<int>& dp) {
  if (step == 0 || step == 1) {
    return 1;
  }

  if (dp[step] != -1) {
    return dp[step];
  }

  return dp[step] = solveMemo(step - 1, dp) + solveMemo(step - 2, dp);
}

int climbStairsMemo(int n) {
  vector<int> dp(n + 1, -1);
  return solveMemo(n, dp);
}

// O(n) - Bottom Up DP
int climbStairsIterative(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

// O(1) Space
int climbStairsOptimized(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  int prev2 = 1;  // dp[0]
  int prev1 = 1;  // dp[1]

  for (int i = 2; i <= n; ++i) {
    int cur = prev1 + prev2;
    prev2 = prev1;
    prev1 = cur;
  }

  return prev1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << "Brute Force: " << climbStairsBrute(n) << '\n';
  cout << "Memoization: " << climbStairsMemo(n) << '\n';
  cout << "Iterative DP: " << climbStairsIterative(n) << '\n';
  cout << "Space Optimized: " << climbStairsOptimized(n) << '\n';

  return 0;
}