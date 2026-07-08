#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// MERGE SORT - ORIGINAL SAFE IMPLEMENTATION
// -----------------------------------------------------------------------------
/*
How it works:
1. Divide the array into two halves recursively until each subarray has one element.
2. Merge the two sorted halves into a single sorted array.
3. Repeat merging process up the recursion until the entire array is sorted.

Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)
- Stable: Yes
- Memory: O(n) (due to temporary vectors for merging)
*/

vector<int> merge_sort(const vector<int>& A) {
    int n = sz(A);
    if (n <= 1) return A; // already sorted

    int mid = n / 2;
    vector<int> left(A.begin(), A.begin() + mid);
    vector<int> right(A.begin() + mid, A.end());

    left = merge_sort(left);
    right = merge_sort(right);

    // merge two sorted halves
    vector<int> merged;
    merged.reserve(n);

    int i = 0, j = 0;
    while (i < sz(left) && j < sz(right)) {
        if (left[i] <= right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }

    while (i < sz(left)) merged.push_back(left[i++]);
    while (j < sz(right)) merged.push_back(right[j++]);

    return merged;
}

// -----------------------------------------------------------------------------
// IN-PLACE MERGE SORT TEMPLATE (CP READY)
// -----------------------------------------------------------------------------
template <class T>
void merge_inplace(vector<T>& a, int l, int r, vector<T>& temp) {
    if (r - l <= 1) return; // single element, already sorted

    int mid = l + (r - l) / 2;
    merge_inplace(a, l, mid, temp);
    merge_inplace(a, mid, r, temp);

    // merge two sorted halves into temp
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i < mid) temp[k++] = a[i++];
    while (j < r) temp[k++] = a[j++];

    for (int x = l; x < r; ++x) a[x] = temp[x];
}

template <class T>
void merge_sort_inplace(vector<T>& a) {
    vector<T> temp(sz(a));
    merge_inplace(a, 0, sz(a), temp);
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
    vector<int> sorted_arr = merge_sort(arr);
    cout << "Sorted array (merge_sort copy):\n";
    print_vector(sorted_arr);

    // Using in-place template version
    merge_sort_inplace(arr);
    cout << "Sorted array (merge_sort_inplace):\n";
    print_vector(arr);

    return 0;
}
