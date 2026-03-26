#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// PRINT VECTOR / ARRAY UTILITY
// -----------------------------------------------------------------------------
template<class T>
void print_vector(const vector<T>& v) {
    for (auto x : v) cout << x << ' ';
    cout << '\n';
}

// -----------------------------------------------------------------------------
// 1) GENERATE PERMUTATIONS
// -----------------------------------------------------------------------------
void generate_permutations(vector<int> arr) {
    sort(all(arr)); // must start with sorted array for next_permutation
    cout << "All permutations:\n";
    do {
        print_vector(arr);
    } while (next_permutation(all(arr)));
}

// -----------------------------------------------------------------------------
// 2) NEXT / PREVIOUS PERMUTATION
// -----------------------------------------------------------------------------
void next_prev_permutation_example() {
    vector<int> arr = {1, 2, 3};
    cout << "Original: "; print_vector(arr);

    next_permutation(all(arr));
    cout << "Next permutation: "; print_vector(arr);

    prev_permutation(all(arr));
    cout << "Previous permutation: "; print_vector(arr);
}

// -----------------------------------------------------------------------------
// 3) COUNT PERMUTATIONS
// -----------------------------------------------------------------------------
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

// Count distinct permutations when array has duplicates
template<class T>
long long count_distinct_permutations(vector<T> arr) {
    sort(all(arr));
    long long res = factorial(sz(arr));
    map<T,int> freq;
    for (auto x : arr) freq[x]++;
    for (auto p : freq) res /= factorial(p.second);
    return res;
}

// -----------------------------------------------------------------------------
// 4) PERMUTATION WITH CONSTRAINTS
// -----------------------------------------------------------------------------
void constrained_permutation_example() {
    vector<int> arr = {1,2,3};
    cout << "Permutations where first element is 1:\n";
    sort(all(arr));
    do {
        if (arr[0] == 1) print_vector(arr);
    } while (next_permutation(all(arr)));
}

// -----------------------------------------------------------------------------
// 5) MEX (Minimum Excluded Number)
// -----------------------------------------------------------------------------
int mex(vector<int> arr) {
    set<int> s(all(arr));
    int m = 0;
    while (s.count(m)) m++;
    return m;
}

// Fast MEX using boolean array (for small numbers)
int mex_fast(vector<int> arr, int n) {
    vector<bool> present(n+1,false);
    for (int x : arr) if (x <= n) present[x] = true;
    for (int i = 0; i <= n; ++i) if (!present[i]) return i;
    return n+1;
}

// -----------------------------------------------------------------------------
// 6) OTHER USEFUL PERMUTATION UTILS
// -----------------------------------------------------------------------------

// Check if array is a valid permutation 1..n
bool is_valid_permutation(vector<int> arr) {
    int n = sz(arr);
    vector<bool> seen(n,false);
    for (int x : arr) {
        if (x < 1 || x > n || seen[x-1]) return false;
        seen[x-1] = true;
    }
    return true;
}

// Generate all permutations of length k from n elements
void k_permutations(int n, int k) {
    vector<int> arr(n);
    iota(all(arr),1); // 1..n
    vector<int> sel(k);
    cout << "All " << k << "-permutations of " << n << " elements:\n";
    do {
        copy(arr.begin(), arr.begin()+k, sel.begin());
        print_vector(sel);
    } while (next_permutation(all(arr)));
}

// -----------------------------------------------------------------------------
// MAIN FUNCTION DEMO
// -----------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1,2,3};

    generate_permutations(arr);
    next_prev_permutation_example();

    cout << "Total distinct permutations: " << count_distinct_permutations(arr) << "\n";

    constrained_permutation_example();

    vector<int> mex_example = {0,1,2,4,5};
    cout << "MEX of {0,1,2,4,5}: " << mex(mex_example) << "\n";

    cout << "Is valid permutation: " << (is_valid_permutation(arr) ? "Yes" : "No") << "\n";

    k_permutations(4,2);

    return 0;
}
