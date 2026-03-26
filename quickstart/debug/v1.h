#pragma once

#ifndef ONLINE_JUDGE

// ===== STANDARD HEADERS =====
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <utility>
#include <cstdlib>   // exit
#include <cstdio>    // FILE*, fscanf, etc.
#include <functional> // apply
using namespace std;

// ============================================================
// BASIC TYPE PRINTERS
// ============================================================
void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(bool x) { cerr << (x ? "true" : "false"); }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(const char* x) { cerr << '"' << x << '"'; }

// ============================================================
// STL PRINTERS
// ============================================================
template <class T, class U>
void _print(pair<T, U> p){ cerr << "("; _print(p.first); cerr << ", "; _print(p.second); cerr << ")"; }

template <class... T>
void _print(tuple<T...> t){ 
    cerr << "{"; 
    apply([](auto&&... args){ int idx=0; ((cerr << (idx++ ? ", ":"") << args), ...); }, t);
    cerr << "}";
}

template <class T>
void _print(vector<T> v){ cerr << "["; for(auto &i:v){ _print(i); cerr << " "; } cerr << "]"; }

template <class T>
void _print(set<T> s){ cerr << "{"; for(auto &i:s){ _print(i); cerr << " "; } cerr << "}"; }

template <class T>
void _print(multiset<T> ms){ cerr << "{"; for(auto &i:ms){ _print(i); cerr << " "; } cerr << "}"; }

template <class K, class V>
void _print(map<K, V> m){ cerr << "{"; for(auto &i:m){ _print(i); cerr << " "; } cerr << "}"; }

// ============================================================
// VARIADIC DEBUG
// ============================================================
void __print_end() { cerr << "]" << endl; }
void __print_all() {} // base case for empty pack

template <typename T, typename... V>
void __print_all(T t, V... v){
    _print(t);
    if(sizeof...(v)) cerr << ", ";
    __print_all(v...);
}

#define debug(x...) cerr << "[" << #x << "] = [", __print_all(x), __print_end()

// ============================================================
// DUMP CONTAINER WITH INDICES
// ============================================================
template <typename T>
void dump_container(const T &cont, string name=""){
    if(!name.empty()) cerr << name << " = ";
    cerr << "[\n";
    int idx=0;
    for(auto &val:cont){ cerr << "  (" << idx++ << ") = "; _print(val); cerr << "\n"; }
    cerr << "]\n";
}

// ============================================================
// TIMER
// ============================================================
chrono::high_resolution_clock::time_point __timer_start;
#define START_TIMER() __timer_start = chrono::high_resolution_clock::now()
#define STOP_TIMER() do{ \
    auto __timer_end = chrono::high_resolution_clock::now(); \
    auto __duration = chrono::duration_cast<chrono::milliseconds>(__timer_end-__timer_start).count(); \
    cerr << "[Execution Time] " << __duration << " ms" << endl; \
}while(0)

// ============================================================
// MEMORY USAGE (Windows placeholder)
// ============================================================
#define MEM_USAGE() cerr << "[Memory] (not implemented on Windows)\n"

// ============================================================
// ASSERTIONS
// ============================================================
#define dassert(cond) do{ if(!(cond)){ cerr << "[Assertion Failed] " << #cond << " at " << __FILE__ << ":" << __LINE__ << "\n"; exit(1); } }while(0)

// ============================================================
// TEST CASE LABELS
// ============================================================
int __case_num=1;
#define TCC cout << "Case #" << __case_num++ << ": "

// ============================================================
// RANDOM GENERATORS
// ============================================================
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
auto rnd_int = [](int l,int r){ uniform_int_distribution<int> dist(l,r); return dist(rng); };
auto rnd_ll = [](long long l,long long r){ uniform_int_distribution<long long> dist(l,r); return dist(rng); };
auto rnd_vec = [](int n,int l,int r){ vector<int> v(n); for(int i=0;i<n;i++) v[i]=rnd_int(l,r); return v; };
auto rnd_string = [](int n,string alphabet="abc"){ string s(n,'a'); for(int i=0;i<n;i++) s[i]=alphabet[rnd_int(0,(int)alphabet.size()-1)]; return s; };

// ============================================================
// STRESS TESTING HELPER
// ============================================================
template <typename Gen, typename Brute, typename Fast>
void stress(Gen gen, Brute brute, Fast fast, int T=1000){
    for(int t=1;t<=T;t++){
        auto in = gen();
        auto out1 = brute(in);
        auto out2 = fast(in);
        if(out1!=out2){ cerr << "[Mismatch at test " << t << "]\n"; debug(in); debug(out1,out2); exit(0); }
    }
    cerr << "[All " << T << " tests passed]\n";
}

// ============================================================
// INPUT TRACER
// ============================================================
template <typename T>
void trace_in(T &x,string name=""){
    if(!(cin>>x)){ cerr << "[Input Error] failed to read " << name << "\n"; exit(1);}
    cerr << "[Read " << name << "] = "; _print(x); cerr << endl;
}

// ============================================================
// OUTPUT COMPARATOR
// ============================================================
template <typename T>
void compare_outputs(const T &a,const T &b,string nameA="A",string nameB="B"){
    if(a==b){ cerr << "[Outputs Match]\n"; return; }
    cerr << "[Outputs Differ]\n"; cerr << nameA << " = "; _print(a); cerr << "\n"; cerr << nameB << " = "; _print(b); cerr << "\n";
}

#else
// DISABLED ON ONLINE JUDGE
#define debug(x...)
#define dump_container(x,y...)
#define START_TIMER()
#define STOP_TIMER()
#define MEM_USAGE()
#define dassert(x)
#define TCC
#endif
