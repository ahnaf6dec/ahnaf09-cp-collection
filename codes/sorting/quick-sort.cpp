#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// QUICK SORT - ORIGINAL SAFE IMPLEMENTATION
// -----------------------------------------------------------------------------
/*
How it works:
1. Choose a pivot element from the array (commonly first, last, or middle element).
2. Partition the array so that elements less than pivot are on the left, elements greater are on the right.
3. Recursively apply Quick Sort to left and right subarrays.
4. Combine the results (recursion handles sorting).
5. Repeat until the array is sorted.

Time Complexity:
- Best case: O(n log n)  (balanced partitions)
- Average case: O(n log n)
- Worst case: O(n^2)     (already sorted or poor pivot choice)
- In-place: Yes
- Not stable
*/

vector<int> quick_sort(vector<int> A) {
    int n = sz(A);
    if (n <= 1) return A; // already sorted

    int pivot = A[n / 2]; // choose middle element as pivot
    vector<int> left, right, equal;

    for (int x : A) {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) equal.push_back(x);
        else right.push_back(x);
    }

    left = quick_sort(left);
    right = quick_sort(right);

    // concatenate left + equal + right
    left.insert(left.end(), all(equal));
    left.insert(left.end(), all(right));
    return left;
}

// -----------------------------------------------------------------------------
// IN-PLACE QUICK SORT TEMPLATE (CP READY)
// -----------------------------------------------------------------------------
template <class T>
int partition(vector<T>& a, int l, int r) {
    T pivot = a[r]; // choose last element as pivot
    int i = l - 1;

    for (int j = l; j < r; ++j) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

template <class T>
void quick_sort_inplace(vector<T>& a, int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort_inplace(a, l, pi - 1);
        quick_sort_inplace(a, pi + 1, r);
    }
}

template <class T>
void quick_sort_inplace(vector<T>& a) {
    quick_sort_inplace(a, 0, sz(a) - 1);
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
    vector<int> sorted_arr = quick_sort(arr);
    cout << "Sorted array (quick_sort copy):\n";
    print_vector(sorted_arr);

    // Using in-place template version
    quick_sort_inplace(arr);
    cout << "Sorted array (quick_sort_inplace):\n";
    print_vector(arr);

    return 0;
}
