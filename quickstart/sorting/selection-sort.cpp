#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// SELECTION SORT - ORIGINAL SAFE IMPLEMENTATION
// -----------------------------------------------------------------------------
/*
How it works:
1. Divide array into two parts: sorted (initially empty) and unsorted (full array).
2. Repeatedly find the minimum element from unsorted part.
3. Swap it with the first element of unsorted part (append to sorted part).
4. Move the boundary of sorted part one step right.
5. Repeat until entire array is sorted.

Time Complexity:
- Best case: O(n^2)
- Average case: O(n^2)
- Worst case: O(n^2)
- In-place, not stable
*/

vector<int> selection_sort(vector<int> A) {
    int n = sz(A);
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // assume first element of unsorted part is minimum

        // find the smallest element in the unsorted portion
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        
        // swap minimum element with the first element of unsorted part
        if (minIndex != i)
            swap(A[i], A[minIndex]);
    }
    return A;
}

// -----------------------------------------------------------------------------
// IN-PLACE COMPACT TEMPLATE VERSION (CP READY)
// -----------------------------------------------------------------------------
template <class T>
void selection_sort_inplace(vector<T>& a) {
    int n = sz(a);
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIndex])
                minIndex = j;
        if (minIndex != i)
            swap(a[i], a[minIndex]);
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

    vector<int> arr = {64, 25, 12, 22, 11, 90, 5};

    cout << "Original array:\n";
    print_vector(arr);

    // Using safe copy implementation
    vector<int> sorted_arr = selection_sort(arr);
    cout << "Sorted array (selection_sort copy):\n";
    print_vector(sorted_arr);

    // Using in-place compact template
    selection_sort_inplace(arr);
    cout << "Sorted array (selection_sort_inplace):\n";
    print_vector(arr);

    return 0;
}
