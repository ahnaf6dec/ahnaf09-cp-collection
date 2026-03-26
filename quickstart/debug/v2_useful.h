#pragma once

#ifndef ONLINE_JUDGE

#include <bits/stdc++.h>
#include <execinfo.h>
#include <unistd.h>
using namespace std;

// ---------------------- BASIC TYPE PRINTERS ----------------------
inline void _print(int x) { cerr << x; }
inline void _print(long long x) { cerr << x; }
inline void _print(double x) { cerr << x; }
inline void _print(long double x) { cerr << x; }
inline void _print(char x) { cerr << '\'' << x << '\''; }
inline void _print(bool x) { cerr << (x ? "true" : "false"); }
inline void _print(const string &x) { cerr << '"' << x << '"'; }
inline void _print(const char* x) { cerr << '"' << x << '"'; }

// ---------------------- STL PRINTERS ----------------------
template<class T, class U>
void _print(const pair<T,U> &p) { cerr << "("; _print(p.first); cerr << ", "; _print(p.second); cerr << ")"; }

template<class T>
void _print(const vector<T> &v) { cerr << "["; for (auto &x : v) { _print(x); cerr << " "; } cerr << "]"; }

template<class T>
void _print(const set<T> &s) { cerr << "{"; for (auto &x : s) { _print(x); cerr << " "; } cerr << "}"; }

template<class T>
void _print(const multiset<T> &s) { cerr << "{"; for (auto &x : s) { _print(x); cerr << " "; } cerr << "}"; }

template<class K, class V>
void _print(const map<K,V> &m) { cerr << "{"; for (auto &x : m) { _print(x); cerr << " "; } cerr << "}"; }

template<class T>
void _print(const unordered_set<T> &s) { cerr << "{"; for (auto &x : s) { _print(x); cerr << " "; } cerr << "}"; }

template<class K, class V>
void _print(const unordered_map<K,V> &m) { cerr << "{"; for (auto &x : m) { _print(x); cerr << " "; } cerr << "}"; }

template<class... T>
void _print(const tuple<T...> &t) {
    cerr << "{";
    std::apply([](auto&&... args){ int idx=0; ((cerr << (idx++ ? ", " : ""), _print(args)), ...); }, t);
    cerr << "}";
}

// ---------------------- VARIADIC DEBUG ----------------------
inline void __print_all() {}
template<typename T, typename... V>
void __print_all(T t, V... v) {
    _print(t);
    if (sizeof...(v)) cerr << ", ";
    __print_all(v...);
}
inline void __print_end() { cerr << "]\n"; }

#define DEBUG(x...) cerr << "[DEBUG] " << __FILE__ << ":" << __LINE__ << " | " << #x << " = [", __print_all(x), __print_end()

// ---------------------- _debug STREAM ----------------------
struct DebugStream {
    template <typename T> DebugStream& operator<<(const T& val) { cerr << val; return *this; }
    DebugStream& operator<<(ostream& (*manip)(ostream&)) { manip(cerr); return *this; }
};
inline DebugStream _debug;

// ---------------------- DUMP CONTAINER ----------------------
template<typename T>
void DUMP_CONTAINER(const T &cont, const string &name="") {
    if (!name.empty()) cerr << "[DUMP] " << name << " =\n";
    int idx=0;
    for (auto &val : cont) { cerr << "  (" << idx++ << ") = "; _print(val); cerr << "\n"; }
}

// ---------------------- TIMER ----------------------
chrono::high_resolution_clock::time_point __timer_start;
#define START_TIMER() __timer_start = chrono::high_resolution_clock::now()
#define STOP_TIMER() do { \
    auto __end = chrono::high_resolution_clock::now(); \
    auto __dur = chrono::duration_cast<chrono::milliseconds>(__end - __timer_start).count(); \
    cerr << "[Execution Time] " << __dur << " ms\n"; \
} while(0)

struct ScopedTimer {
    string label; chrono::high_resolution_clock::time_point start;
    ScopedTimer(string s) : label(move(s)), start(chrono::high_resolution_clock::now()) {}
    ~ScopedTimer() {
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr << "[" << label << "] took " << dur << " ms\n";
    }
};

// ---------------------- MEMORY USAGE ----------------------
inline long get_memory_kb() {
    FILE* file = fopen("/proc/self/status", "r"); if (!file) return -1;
    char line[256]; while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "VmRSS:", 6) == 0) { long kb; sscanf(line+6,"%ld",&kb); fclose(file); return kb; }
    }
    fclose(file); return -1;
}

// ---------------------- ASSERTIONS & BACKTRACE ----------------------
inline void print_backtrace() {
    void* array[20]; int size = backtrace(array, 20);
    cerr << "--- Stack Trace ---\n";
    char** symbols = backtrace_symbols(array, size);
    for (int i=0; i<size; i++) cerr << symbols[i] << "\n";
    free(symbols);
}
#define dassert(cond) do { if (!(cond)) { cerr << "[Assertion Failed] " << #cond << " at " << __FILE__ << ":" << __LINE__ << "\n"; print_backtrace(); exit(1); } } while(0)

// ---------------------- RANDOM HELPERS ----------------------
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
inline int rnd_int(int l,int r){ return uniform_int_distribution<int>(l,r)(rng); }
inline long long rnd_ll(long long l,long long r){ return uniform_int_distribution<long long>(l,r)(rng); }
inline vector<int> rnd_vec(int n,int l,int r){ vector<int> v(n); for(auto &x:v) x=rnd_int(l,r); return v; }

// ---------------------- STRESS TEST ----------------------
template<typename Gen, typename Brute, typename Fast>
void stress(Gen gen, Brute brute, Fast fast, int T=100) {
    for(int t=1;t<=T;++t){
        auto in=gen();
        auto a=brute(in), b=fast(in);
        if(a!=b){ cerr<<"[Mismatch at test "<<t<<"]\n"; DEBUG(in,a,b); exit(0);}
    }
    cerr<<"[All "<<T<<" tests passed]\n";
}

#else
// ---------------------- ONLINE JUDGE ----------------------
#define DEBUG(x...)
#define DUMP_CONTAINER(x,y...)
#define START_TIMER()
#define STOP_TIMER()
#define dassert(x)
#define print_backtrace()
struct ScopedTimer { ScopedTimer(const std::string&){} ~ScopedTimer(){} };
struct _NullDebugStream { template<typename T> _NullDebugStream& operator<<(const T&) { return *this; } _NullDebugStream& operator<<(std::ostream& (*)(std::ostream&)) { return *this; } };
static _NullDebugStream _debug;
inline long get_memory_kb(){return -1;}
template<typename Gen, typename Brute, typename Fast> void stress(Gen,Brute,Fast,int=0){}
inline int rnd_int(int l,int r){return l;}
inline long long rnd_ll(long long l,long long r){return l;}
inline vector<int> rnd_vec(int n,int l,int r){return vector<int>(n,l);}
#endif
