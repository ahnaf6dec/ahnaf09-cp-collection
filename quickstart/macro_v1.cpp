// In the Name of Allah
// Author : Algorider
// File   : competitive_macros.cpp

#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------------------
 | Typedefs
 --------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tuple<int,int,int> t3i;
typedef tuple<ll,ll,ll> t3l;

/*--------------------------------------------------------------
 | Useful Constants
 --------------------------------------------------------------*/
const int INF = 1e9+7;
const ll LINF = 1e18;
const ld PI = 3.14159265358979323846;
const ld EPS = 1e-9;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const ll MOD2 = 1000000009;
const ll MOD3 = 1e9+21;
const int dx[8] = {-1,0,1,0,-1,-1,1,1};
const int dy[8] = {0,1,0,-1,-1,1,-1,1};

/*--------------------------------------------------------------
 | General Macros
 --------------------------------------------------------------*/
#define endl '\n'
#define sp ' '
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yO "YES\n"
#define nO "NO\n"
#define yo "Yes\n"
#define no "No\n"
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))
#define sq(x) ((x) * (x))

// Vector and BS stuff
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v), 0LL)
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

// Loops
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define RREP(i, a, b) for(int i = (a); i >= (b); --i)
#define FOREACH(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define FORE(a, v) for(auto &a : v)

// Bitwise Macros
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define SETBIT(x, i) ((x) |  (1LL << (i)))
#define CLEARBIT(x, i) ((x) & ~(1LL << (i)))
#define FLIPBIT(x, i) ((x) ^  (1LL << (i)))
#define LOWBIT(x) ((x) & -(x))

// Math Helpers
#define CHKMIN(a, b) if(a > b) a = b
#define CHKMAX(a, b) if(a < b) a = b
#define POW2(x) (1LL<<(x))
#define MODADD(a, b, m) (((a) + (b)) % (m))
#define MODSUB(a, b, m) (((a) - (b) + (m)) % (m))
#define MODMUL(a, b, m) (((a) * (b)) % (m))
#define MODINV(a, m) binpow(a, m-2, m) // a^(m-2) mod m assuming m is prime

// Fast IO
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

bool allElEq(const vector<int>&v) {
  if(v.empty() || sz(v) == 1) return true;
  return adjacent_find(all(v), not_equal_to<int>()) == v.end();
}

bool all_even(int x, int y, int z) {
    return !(x & 1) && !(y & 1) && !(z & 1);
}



// checking perfect sqaure, prime, get character a-z

ll digitsum(ll a){ll b=0;while(a>0){b+=a%10;a/=10;}return b;}
ll factorial(ll a){ll b=1;while(a>0){b*=a;a--;}return b;}
ll ceildiv(ll a, ll b){ll q;q=a/b+(a%b!=0);return q;}

const int MOD=1e9+7;
const int mod=998244353;
bool isPerfectSquare(ll x){if(x>=0){ll sr=sqrt(x);return (sr*sr==x);}return false;}
bool isPrime(ll n){if(n<=1)return false;for(ll i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
bool isPal(ll x){string s="";while(x){s+=x%10;x/=10;}string t=s;reverse(all(s));return s==t;}
char letter(ll n){string alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";return alphabet[n];}

#define ckmin(a, b) a = min(a, b)
#define ckmax(a, b) a = max(a, b)
// bin pow
inline ll binpow(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// check all elements in vectors same or not
template<typename T>
bool allEqual(const std::vector<T>& v){return sz(v)<2||std::adjacent_find(all(v),std::not_equal_to<T>())==v.end();}
