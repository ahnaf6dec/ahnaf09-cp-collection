#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// FUNCTION: MAXIMUM EXCLUDED ELEMENT (largest number not in array within 0..max(arr))
// -----------------------------------------------------------------------------
int max_excluded_element(const vector<int>& arr) {
    if (arr.empty()) return 0;

    int mx = *max_element(arr.begin(), arr.end());
    vector<bool> present(mx + 2, false); // +2 to handle mx+1
    for (int x : arr) if (x <= mx + 1) present[x] = true;

    // Find the largest number in 0..mx+1 that is not present
    for (int i = mx + 1; i >= 0; --i)
        if (!present[i])
            return i;

    return -1; // should not happen
}

// -----------------------------------------------------------------------------
// MAIN DEMO
// -----------------------------------------------------------------------------
int main() {
    vector<int> arr = {0, 1, 2, 4, 5, 7};

    cout << "Array: ";
    for (int x : arr) cout << x << ' ';
    cout << "\n";

    int mex_max = max_excluded_element(arr);
    cout << "Maximum Excluded Element: " << mex_max << "\n";

    return 0;
}
