#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using clk = chrono::high_resolution_clock;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll l,ll r){ return uniform_int_distribution<ll>(l,r)(rng); }
int rndi(int l,int r){ return uniform_int_distribution<int>(l,r)(rng); }
double rndd(double l,double r){ return uniform_real_distribution<double>(l,r)(rng); }

string rands(int n,string s="abc"){
    string t(n,'a');
    for(char &c:t) c=s[rndi(0,(int)s.size()-1)];
    return t;
}

vector<int> rvec(int n,int l,int r){
    vector<int>a(n);
    for(auto &x:a) x=rndi(l,r);
    return a;
}

vector<pair<int,int>> rgraph(int n,int m){
    vector<pair<int,int>> e;
    for(int i=0;i<m;i++){
        int u=rndi(1,n), v=rndi(1,n);
        e.push_back({u,v});
    }
    return e;
}

template<class T>
string str(T x){ stringstream ss; ss<<x; return ss.str(); }

template<class T>
void pr(const T &x){ cerr<<x; }

template<class A,class B>
void pr(const pair<A,B>&p){ cerr<<"("<<p.first<<","<<p.second<<")"; }

template<class T>
void pr(const vector<T>&v){
    cerr<<"[";
    for(int i=0;i<(int)v.size();i++){
        pr(v[i]);
        if(i+1<v.size()) cerr<<" ";
    }
    cerr<<"]";
}

template<class T>
void dbg(T t){ pr(t); }

template<class T,class...V>
void dbg(T t,V...v){
    pr(t);
    if(sizeof...(v)) cerr<<" ";
    dbg(v...);
}

#define debug(...) cerr<<"["<<#__VA_ARGS__<<"] = ", dbg(__VA_ARGS__), cerr<<"\n"

void save_fail(string s){
    ofstream f("fail.txt");
    f<<s;
    f.close();
}

template<class Gen,class Brute,class Fast>
void stress(Gen gen,Brute brute,Fast fast,int T=1000){
    for(int t=1;t<=T;t++){
        auto in=gen();
        auto a=brute(in);
        auto b=fast(in);
        if(a!=b){
            cerr<<"WA at test "<<t<<"\n";
            debug(in);
            cerr<<"brute="<<a<<" fast="<<b<<"\n";
            save_fail(str(in));
            exit(0);
        }
    }
    cerr<<"OK "<<T<<"\n";
}

template<class F>
double timer(F f){
    auto s=clk::now();
    f();
    auto e=clk::now();
    return chrono::duration<double,milli>(e-s).count();
}

template<class Gen,class Fast>
void tle_check(Gen gen,Fast fast,int T=100){
    for(int t=1;t<=T;t++){
        auto in=gen();
        double ms=timer([&]{ fast(in); });
        if(ms>1000){
            cerr<<"TLE at test "<<t<<" time="<<ms<<"ms\n";
            debug(in);
            exit(0);
        }
    }
    cerr<<"TLE check passed\n";
}

struct Test{
    int n;
    vector<int>a;
};

Test gen_array(){
    Test t;
    t.n=rndi(1,20);
    t.a=rvec(t.n,-100,100);
    return t;
}

Test gen_string(){
    Test t;
    t.n=rndi(1,20);
    string s=rands(t.n,"abcxyz");
    t.a.assign(s.begin(),s.end());
    return t;
}

Test gen_mixed(){
    Test t;
    t.n=rndi(1,20);
    t.a=rvec(t.n,0,10);
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto gen=gen_array;

    auto brute=[](Test t)->ll{
        ll s=0;
        for(int x:t.a) s+=x;
        return s;
    };

    auto fast=[](Test t)->ll{
        ll s=0;
        for(int x:t.a) s+=x;
        return s;
    };

    stress(gen,brute,fast,500);
    tle_check(gen,fast,100);
}
