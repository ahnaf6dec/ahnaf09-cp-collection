#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

constexpr ll INFLL = 4e18;
constexpr int INF = 1e9;

ll modpow(ll a, ll b, ll mod) {
    ll res = 1 % mod;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	Solution sol;
	
	sol.mapWordWeights();
	return 0;
}



