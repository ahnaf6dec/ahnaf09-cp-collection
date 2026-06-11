#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------
    1. Pure Recursion
    Time Complexity : O(2^n)
    Space Complexity: O(n)
--------------------------------------------------*/
int fibRec(int n) {
  if (n <= 1) return n;

  return fibRec(n - 1) + fibRec(n - 2);
}

/*--------------------------------------------------
    2. Recursion + Memoization (Top-Down DP)
    Time Complexity : O(n)
    Space Complexity: O(n)
--------------------------------------------------*/
int fibMemo(int n, vector<int>& memo) {
  if (n <= 1) return n;

  if (memo[n] != -1) return memo[n];

  return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
}

/*--------------------------------------------------
    3. Iterative DP (Bottom-Up DP)
    Time Complexity : O(n)
    Space Complexity: O(n)
--------------------------------------------------*/
int fibDP(int n) {
  if (n <= 1) return n;

  vector<int> dp(n + 1);

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

/*--------------------------------------------------
    4. Space Optimized DP
    Time Complexity : O(n)
    Space Complexity: O(1)
--------------------------------------------------*/
int fibOptimized(int n) {
  if (n <= 1) return n;

  int prev2 = 0;  // F(0)
  int prev1 = 1;  // F(1)

  for (int i = 2; i <= n; i++) {
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

  cout << "Pure Recursion     : " << fibRec(n) << '\n';

  vector<int> memo(n + 1, -1);
  cout << "Memoization DP     : " << fibMemo(n, memo) << '\n';

  cout << "Iterative DP       : " << fibDP(n) << '\n';

  cout << "Space Optimized DP : " << fibOptimized(n) << '\n';

  return 0;
}