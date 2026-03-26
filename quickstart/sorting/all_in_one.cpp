#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

// -----------------------------------------------------------------------------
// PRINT VECTOR / ARRAY UTILITY
// -----------------------------------------------------------------------------
template<class T>
void print_vector(const vector<T>& v) {
    for (auto x : v) cout << x << ' ';
    cout << endl;
}

// -----------------------------------------------------------------------------
// CLASSICAL SORTS
// -----------------------------------------------------------------------------

// Bubble Sort
template<class T>
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

// Selection Sort
template<class T>
void selection_sort_inplace(vector<T>& a) {
    int n = sz(a);
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIndex])
                minIndex = j;
        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort
template<class T>
void insertion_sort_inplace(vector<T>& a) {
    int n = sz(a);
    for (int i = 1; i < n; ++i) {
        T key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) a[j + 1] = a[j--];
        a[j + 1] = key;
    }
}

// Merge Sort
template<class T>
void merge(vector<T>& a, int l, int m, int r, vector<T>& temp) {
    int i = l, j = m, k = l;
    while (i < m && j < r) temp[k++] = (a[i] <= a[j] ? a[i++] : a[j++]);
    while (i < m) temp[k++] = a[i++];
    while (j < r) temp[k++] = a[j++];
    for (int t = l; t < r; ++t) a[t] = temp[t];
}

template<class T>
void merge_sort_inplace(vector<T>& a, int l, int r, vector<T>& temp) {
    if (r - l <= 1) return;
    int m = l + (r - l) / 2;
    merge_sort_inplace(a, l, m, temp);
    merge_sort_inplace(a, m, r, temp);
    merge(a, l, m, r, temp);
}

template<class T>
void merge_sort_inplace(vector<T>& a) {
    vector<T> temp(sz(a));
    merge_sort_inplace(a, 0, sz(a), temp);
}

// Quick Sort
template<class T>
int partition(vector<T>& a, int l, int r) {
    T pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
        if (a[j] <= pivot) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

template<class T>
void quick_sort_inplace(vector<T>& a, int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort_inplace(a, l, pi - 1);
        quick_sort_inplace(a, pi + 1, r);
    }
}

template<class T>
void quick_sort_inplace(vector<T>& a) {
    quick_sort_inplace(a, 0, sz(a) - 1);
}

// -----------------------------------------------------------------------------
// STL SORTING UTILITIES
// -----------------------------------------------------------------------------
/*
Useful STL utilities for contests:
- sort(v.begin(), v.end())
- stable_sort(v.begin(), v.end())
- reverse(v.begin(), v.end())
- is_sorted(v.begin(), v.end())
- unique + erase to remove duplicates
- nth_element for kth largest/smallest
*/
template<class T>
void stl_sort_examples(vector<T>& v) {
    sort(all(v));                   // ascending
    stable_sort(all(v));            // stable sort
    reverse(all(v));                // reverse
    bool sorted_flag = is_sorted(all(v)); // check sorted
}

// -----------------------------------------------------------------------------
// BINARY SEARCH + LOWER/UPPER BOUNDS
// -----------------------------------------------------------------------------
template<class T>
void binary_search_demo(vector<T>& v, T x) {
    sort(all(v)); // required
    cout << "binary_search: " << binary_search(all(v), x) << endl;
    auto lb = lower_bound(all(v), x) - v.begin();
    auto ub = upper_bound(all(v), x) - v.begin();
    cout << "lower_bound: " << lb << ", upper_bound: " << ub << endl;
}

// -----------------------------------------------------------------------------
// SORTING APPLICATIONS
// -----------------------------------------------------------------------------

// Coordinate compression
template<class T>
unordered_map<T,int> coordinate_compression(vector<T> arr) {
    vector<T> sorted_arr = arr;
    sort(all(sorted_arr));
    sorted_arr.erase(unique(all(sorted_arr)), sorted_arr.end());
    unordered_map<T,int> compress;
    for (int i = 0; i < sz(sorted_arr); ++i) compress[sorted_arr[i]] = i;
    return compress;
}

// Sort + count unique
template<class T>
int count_unique(vector<T> arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
    return sz(arr);
}

// Sort + group elements
template<class T>
void group_elements(vector<T> arr) {
    sort(all(arr));
    int i = 0;
    while (i < sz(arr)) {
        int val = arr[i], j = i;
        while (j < sz(arr) && arr[j] == val) ++j;
        cout << val << " occurs " << j-i << " times\n";
        i = j;
    }
}

// Sort + greedy optimization (example: max non-overlapping intervals)
struct Interval { int start, end; };
int max_non_overlapping_intervals(vector<Interval> intervals) {
    sort(all(intervals), [](Interval &a, Interval &b){ return a.end < b.end; });
    int count = 0, last_end = -1;
    for (auto &it : intervals) if (it.start >= last_end) { count++; last_end = it.end; }
    return count;
}

// Sort + two pointers (example: count pairs with sum <= target)
int two_pointers_pairs(vector<int> arr, int target) {
    sort(all(arr));
    int left = 0, right = sz(arr)-1, pairs = 0;
    while (left < right) {
        if (arr[left] + arr[right] <= target) {
            pairs += right - left;
            left++;
        } else right--;
    }
    return pairs;
}

// -----------------------------------------------------------------------------
// STRING SORTING
// -----------------------------------------------------------------------------
void sort_strings_example(vector<string>& strs) {
    sort(all(strs)); // lexicographical
    sort(all(strs), [](string &a, string &b){ return a.size() < b.size(); }); // by length
}

// -----------------------------------------------------------------------------
// PREFIX SUM UTILITIES
// -----------------------------------------------------------------------------
vector<long long> prefix_sums(vector<int>& arr) {
    sort(all(arr));
    vector<long long> prefix(sz(arr)+1, 0);
    for (int i = 0; i < sz(arr); ++i) prefix[i+1] = prefix[i] + arr[i];
    return prefix;
}

// -----------------------------------------------------------------------------
// MAIN FUNCTION DEMO
// -----------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {5,2,9,1,7,2,5,9};
    cout << "Original array: ";
    print_vector(arr);

    bubble_sort_inplace(arr);
    cout << "Bubble sorted: ";
    print_vector(arr);

    selection_sort_inplace(arr);
    cout << "Selection sorted: ";
    print_vector(arr);

    insertion_sort_inplace(arr);
    cout << "Insertion sorted: ";
    print_vector(arr);

    vector<int> arr2 = {64,34,25,12,22,11,90,5};
    merge_sort_inplace(arr2);
    cout << "Merge sorted: ";
    print_vector(arr2);

    quick_sort_inplace(arr2);
    cout << "Quick sorted: ";
    print_vector(arr2);

    binary_search_demo(arr2, 25);

    cout << "Count unique: " << count_unique(arr2) << endl;

    cout << "Group elements:\n";
    group_elements(arr2);

    vector<Interval> intervals = {{1,4},{3,5},{0,6},{5,7},{8,9}};
    cout << "Max non-overlapping intervals: " << max_non_overlapping_intervals(intervals) << endl;

    cout << "Pairs with sum <= 10: " << two_pointers_pairs(arr2, 10) << endl;

    vector<string> strs = {"banana","apple","kiwi","apricot","pear"};
    sort_strings_example(strs);
    cout << "Strings sorted lexicographically: ";
    print_vector(strs);

    vector<long long> prefix = prefix_sums(arr2);
    cout << "Prefix sums: ";
    print_vector(prefix);

    unordered_map<int,int> compress = coordinate_compression(arr2);
    cout << "Coordinate compression:\n";
    for (auto &p : compress) cout << p.first << " -> " << p.second << endl;

    return 0;
}
