#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

vector<int> printDivisorsLinear(int n = 1) {
  vector<int> ans;
  for (int i = 1; i <= n; ++i)
    if (n % i == 0)
      ans.push_back(i);
  return ans;
}

vector<int> printDivisorsOptimized(int n = 1) {
  vector<int> ans;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i != n / i)
        ans.push_back(n / i); // avoid duplicate
    }
  }
  // sort(ans.begin(), ans.end());
  return ans;
}

// Most efficient one for calculate divisors
template<class T>
auto divisors(T N){
  using U = conditional_t<is_signed_v<T>, make_unsigned_t<T>, T>;
  U n = (N < 0 ? U(-N) : U(N));
  vector<U> lo, hi;
  for(U i = 1; i <= n / i; ++i){
    if(n % i == 0){
      lo.push_back(i);
      if(i != n / i) hi.push_back(n / i);
    }
  }
  lo.insert(lo.end(), hi.rbegin(), hi.rend());
  return lo; // vector<U>
}

// Usage
  long long n;
  if(!(cin >> n)) return 0;
  auto d = divisors(n);
  for(auto x: d) cout << x << ' ';
  cout << '\n';


// long long version
vector<ll> printDivisorsOptimized(ll n=1){
  vector<ll>a,b;
  for(ll i=1;i<=n/i;++i)
    if(n%i==0){a.push_back(i);if(i!=n/i)b.push_back(n/i);}
  a.insert(a.end(),b.rbegin(),b.rend());
  return a;
}

// sometimes need to count divisors 1 to N (input) i am use precompute



const int N = 1e6;
int divsrs[N+1];


main()
  for(int i = 1; i <= N; ++i) {
    for(int j = i; j <= N; j+=i) {
      divsrs[j]++;
    }
  }
  




int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  // Linear
  auto divLinear = printDivisorsLinear(n);
  cout << "Divisors (Linear): ";
  for (int d : divLinear) cout << d << ' ';
  cout << endl;
  auto divOptimized = printDivisorsOptimized(n);
  cout << "Divisors (Optimized): ";
  for (int d : divOptimized) cout << d << ' ';
  cout << endl;

  return 0;
}

