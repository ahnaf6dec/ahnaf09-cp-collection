#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// INSERTION SORT - ORIGINAL SAFE IMPLEMENTATION
// -----------------------------------------------------------------------------
/*
How it works:
1. Consider the first element as sorted.
2. Take the next element from the unsorted portion.
3. Insert it into the correct position in the sorted portion by shifting larger elements to the right.
4. Repeat steps 2-3 for all remaining elements.
5. After all elements are inserted, the array is sorted.

Time Complexity:
- Best case: O(n)     (already sorted)
- Average case: O(n^2)
- Worst case: O(n^2)  (reverse sorted)
- In-place, stable
*/

vector<int> insertion_sort(vector<int> A) {
    int n = sz(A);
    for (int i = 1; i < n; ++i) {
        int key = A[i];      // element to insert
        int j = i - 1;

        // Move elements of A[0..i-1] that are greater than key
        // one position ahead to make space for key
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key; // insert key at correct position
    }
    return A;
}

// -----------------------------------------------------------------------------
// IN-PLACE COMPACT TEMPLATE VERSION (CP READY)
// -----------------------------------------------------------------------------
template <class T>
void insertion_sort_inplace(vector<T>& a) {
    int n = sz(a);
    for (int i = 1; i < n; ++i) {
        T key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
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
    vector<int> sorted_arr = insertion_sort(arr);
    cout << "Sorted array (insertion_sort copy):\n";
    print_vector(sorted_arr);

    // Using in-place compact template
    insertion_sort_inplace(arr);
    cout << "Sorted array (insertion_sort_inplace):\n";
    print_vector(arr);

    return 0;
}
