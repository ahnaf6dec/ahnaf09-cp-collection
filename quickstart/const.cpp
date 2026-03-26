/*
  In the name of Allah..
        Author : ahnaf09
*/

#include <bits/stdc++.h>
using namespace std;

// ================= TYPE =================
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// ================= MACROS =================
#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)

// ================= CONSTANTS =================
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

const int MOD = 1e9+7;
const int MOD2 = 998244353;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const ld EPSL = 1e-12;

const int N = 2e5+5;
const int LOG = 20;

// grid movement
int dx4[4] = {1,-1,0,0};
int dy4[4] = {0,0,1,-1};

// ================= MIN/MAX =================
template<class T> bool chmin(T &a, T b){ return b<a ? a=b,1:0; }
template<class T> bool chmax(T &a, T b){ return a<b ? a=b,1:0; }

// ================= BIT =================
#define bit(x,i) ((x>>i)&1)
#define setbit(x,i) (x|(1LL<<i))
#define clrbit(x,i) (x&(~(1LL<<i)))

// ================= DEBUG =================
#ifdef OFFLINE
#define dbg(x) cerr<<#x<<"="<<(x)<<endl
#define dbg2(x,y) cerr<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<endl
template<class T> void dbv(const T& v){
  cerr<<"[ "; for(auto &x:v) cerr<<x<<" "; cerr<<"]\n";
}
#else
#define dbg(x) ((void)0)
#define dbg2(x,y) ((void)0)
template<class T> void dbv(const T& v){}
#endif

// ================= RANDOM =================
#ifdef OFFLINE
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return uniform_int_distribution<int>(l,r)(rng); }
ll rndll(ll l,ll r){ return uniform_int_distribution<ll>(l,r)(rng); }
#endif

// ================= DIVISION =================
ll floordiv(ll a, ll b){
  assert(b != 0);
  if(b < 0) a = -a, b = -b;
  if(a >= 0) return a / b;
  return - ( ( -a + b - 1 ) / b );
}

ll ceildiv(ll a, ll b){
  assert(b != 0);
  if(b < 0) a = -a, b = -b;
  if(a >= 0) return (a + b - 1) / b;
  return - ( (-a) / b );
}

// gcd
ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

// lcm
ll lcm(ll a, ll b){
  return a / gcd(a,b) * b;
}

// fast power (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD){
  ll res = 1;
  a %= mod;
  while(b){
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

// modular inverse (only if mod is prime)
ll modinv(ll a, ll mod = MOD){
  return modpow(a, mod - 2, mod);
}

// ================= nCr (COMBINATION) =================
ll fact[N], invfact[N];

void init_nCr(){
  fact[0] = 1;
  for(int i=1;i<N;i++) fact[i] = fact[i-1]*i % MOD;

  invfact[N-1] = modinv(fact[N-1]);
  for(int i=N-2;i>=0;i--) invfact[i] = invfact[i+1]*(i+1) % MOD;
}

ll nCr(int n, int r){
  if(r<0 || r>n) return 0;
  return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}
