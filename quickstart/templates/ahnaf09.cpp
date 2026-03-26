/*
  In the name of Allah..
      _       _                     __   ___
  __ _| |__   | |__    _ __    ___  / _| / _ \
 / _` | '_ \  | '_ \  | '_ \  / _ \| |_ | (_) |
| (_| | | | | | | | | | | | ||  __/|  _| \__, |
 \__,_|_| |_| |_| |_| |_| |_| \___||_|     /_/

        Author : ahnaf09
*/
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ull=unsigned long long;
#define endl '\n'
#define sz(x) (int)(x).size()

// generators
#ifdef OFFLINE
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rnd_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll rnd_ll(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
string rnd_str(int n,string s="abc"){string t;for(int i=0;i<n;i++)t+=s[rnd_int(0,sz(s)-1)];return t;}
#endif
// debug
#ifdef OFFLINE
#define dbg(x) cerr<<#x<<"="<<(x)<<endl
#define dbg2(x,y) cerr<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<endl
template<class T> void dbv(const T& v,string n=""){cerr<<(n.empty()?"":n+"=")<<"[ ";for(auto &x:v)cerr<<x<<" ";cerr<<"]\n";}
template<class A,class B> void dbp(const pair<A,B>& p,string n=""){cerr<<(n.empty()?"":n+"=")<<"("<<p.first<<","<<p.second<<")\n";}
template<class T> void dbvp(const T& v,string n=""){cerr<<(n.empty()?"":n+"=")<<"[ ";for(auto &p:v)cerr<<"("<<p.first<<","<<p.second<<") ";cerr<<"]\n";}
#else
#define dbg(x) ((void)0)
#define dbg2(x,y) ((void)0)
template<class T> void dbv(const T&,string=""){}
template<class A,class B> void dbp(const pair<A,B>&,string=""){}
template<class T> void dbvp(const T&,string=""){}
#endif

void Solve(){
  
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
#ifdef OFFLINE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  clock_t st=clock();
#endif

  int T=1; 
  // cin>>T; 
  for(int tc=1; tc<=T; tc++){
#ifdef OFFLINE
    cout<<"Case #"<<tc<<": ";
#endif
    Solve();
  }

#ifdef OFFLINE
  cerr<<"Time: "<<fixed<<setprecision(3)<<(double)(clock()-st)*1000/CLOCKS_PER_SEC<<" ms\n";
#endif

  return 0;
}
