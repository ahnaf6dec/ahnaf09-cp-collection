#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// BUBBLE SORT - ORIGINAL SAFE IMPLEMENTATION
// -----------------------------------------------------------------------------
/*
How it works:
1. Repeatedly step through the array.
2. Compare each pair of adjacent elements.
3. Swap them if they are in the wrong order.
4. After each pass, the largest unsorted element "bubbles" to its correct position.
5. Repeat until the array is sorted.

Time Complexity:
- Best case: O(n)     (if optimized with swapped flag)
- Average case: O(n^2)
- Worst case: O(n^2)
- In-place: Yes
- Stable: Yes
*/

vector<int> bubble_sort(vector<int> A) {
    int n = sz(A);
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is sorted
        if (!swapped) break;
    }
    return A;
}

// -----------------------------------------------------------------------------
// IN-PLACE COMPACT TEMPLATE (CP READY)
// -----------------------------------------------------------------------------
template <class T>
void bubble_sort_inplace(vector<T>& a) {
    int n = sz(a);
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// -----------------------------------------------------------------------------
// PRINT VECTOR UTILITY
// -----------------------------------------------------------------------------
template <class T>
void print_vector(const vector<T>& v) {
    for (auto x : v)
        cout << x << ' ';
    cout << '\n';
}

// -----------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5};

    cout << "Original array:\n";
    print_vector(arr);

    // Using safe copy implementation
    vector<int> sorted_arr = bubble_sort(arr);
    cout << "Sorted array (bubble_sort copy):\n";
    print_vector(sorted_arr);

    // Using in-place template version
    bubble_sort_inplace(arr);
    cout << "Sorted array (bubble_sort_inplace):\n";
    print_vector(arr);

    return 0;
}
