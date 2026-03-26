#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dp;
int ct = 0;


int fibo(int n) {
  if (n <= 1) return n;

  if (dp[n] != -1) {
    return dp[n];
  }
  ++ct;
  return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int ct1 = 0;
int f(int n) {
	if(n <= 1) return n;
	++ct1;
	return f(n-1) + f(n-2);
}


signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;

  dp.assign(n + 1, -1);  // initialize dp

  cout << fibo(n) << '\n';
  cout << "(dp)total : " << ++ct << " times " << endl;
	cout << "(without dp)total : " << ++ct1 << " times " << endl;
  return 0;
}
