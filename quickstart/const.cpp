#include <cmath>

namespace Constants {

// -----------------------------------------------------------------------------
// 1. INFINITY & NUMERICAL BOUNDS
// -----------------------------------------------------------------------------
constexpr int INF = 1e9;             // Safe 32-bit integer infinity (prevents overflow on addition)
constexpr long long LINF = 1e18;     // Safe 64-bit long long infinity


// -----------------------------------------------------------------------------
// 2. COMBINATORIAL & RANGE LIMITS
// -----------------------------------------------------------------------------
constexpr int N = 2e5 + 5;           // Default constraint boundary for arrays and graphs
constexpr int LOG = 20;              // Sufficient binary lifting limit (2^20 > 10^6 nodes)


// -----------------------------------------------------------------------------
// 3. MODULAR ARITHMETIC CONSTANTS
// -----------------------------------------------------------------------------
constexpr int MOD = 1e9 + 7;         // Standard primary modulo
constexpr int MOD2 = 998244353;      // NTT (Number Theoretic Transform) friendly modulo


// -----------------------------------------------------------------------------
// 4. PRECISION FLOAT ADJUSTMENTS
// -----------------------------------------------------------------------------
constexpr double PI = 3.14159265358979323846;
constexpr double EPS = 1e-9;         // Precision error threshold for standard double types
constexpr long double EPSL = 1e-12;  // Precision error threshold for high-precision long doubles


// -----------------------------------------------------------------------------
// 5. GRID TRAVERSAL VECTORS
// -----------------------------------------------------------------------------
// Standard 4-Directional Movement (Down, Up, Right, Left)
constexpr int dx4[4] = {1, -1, 0, 0};
constexpr int dy4[4] = {0, 0, 1, -1};

// Standard 8-Directional Movement (Includes Diagonals)
constexpr int dx8[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
constexpr int dy8[8] = {0, 1, 0, -1, -1, 1, -1, 1};

} // namespace Constants