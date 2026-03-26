#ifndef ONLINE_JUDGE

#include "debug2.h" // full debug features

#else

// no-op replacements for OJ
#define DEBUG(...) ((void)0)
#define DUMP_CONTAINER(x, ...) ((void)0)
#define START_TIMER() ((void)0)
#define STOP_TIMER() ((void)0)
#define dassert(cond) ((void)0)
struct ScopedTimer { ScopedTimer(const std::string&) {} ~ScopedTimer() {} };
struct _NullDebugStream {
    template<typename T> _NullDebugStream& operator<<(const T&) { return *this; }
    _NullDebugStream& operator<<(std::ostream& (*)(std::ostream&)) { return *this; }
};
static _NullDebugStream _debug;
inline long get_memory_kb() { return -1; }
inline void print_backtrace() { /* no-op */ }
template <typename Gen, typename Brute, typename Fast>
void stress(Gen, Brute, Fast, int = 0) { /* no-op */ }
struct _NullRNG {
    template<typename T> T operator()(T a, T b) { return a; }
};
static _NullRNG rnd_int, rnd_ll, rnd_vec;

#endif // ONLINE_JUDGE

