#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// -----------------------------------------------------------------------------
// PRINT VECTOR UTILITY
// -----------------------------------------------------------------------------
template <class T>
void print_vector(const vector<T>& v) {
    for (auto x : v) cout << x << ' ';
    cout << '\n';
}

// -----------------------------------------------------------------------------
// 1) Sorting before Binary Search
// -----------------------------------------------------------------------------
void sorting_before_binary_search() {
    cout << "1) Sorting before Binary Search\n";
    vector<int> arr = {5, 2, 9, 1, 7};
    sort(all(arr));  // required for binary search functions

    cout << "Sorted array: ";
    print_vector(arr);

    int x = 7;
    if (binary_search(all(arr), x)) {
        cout << x << " found!\n";
    } else {
        cout << x << " not found.\n";
    }
    cout << '\n';
}

// -----------------------------------------------------------------------------
// 2) Sorting before Greedy Algorithms (e.g., interval scheduling)
// -----------------------------------------------------------------------------
struct Interval {
    int start, end;
};

void sorting_before_greedy() {
    cout << "2) Sorting before Greedy Algorithms\n";
    vector<Interval> intervals = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};

    // Sort intervals by end time for classic interval scheduling
    sort(all(intervals), [](const Interval &a, const Interval &b) {
        return a.end < b.end;
    });

    cout << "Intervals sorted by end time:\n";
    for (auto &it : intervals)
        cout << "[" << it.start << "," << it.end << "] ";
    cout << '\n';

    // Greedy selection example
    int count = 0, last_end = -1;
    for (auto &it : intervals) {
        if (it.start >= last_end) {
            count++;
            last_end = it.end;
        }
    }
    cout << "Maximum non-overlapping intervals: " << count << "\n\n";
}

// -----------------------------------------------------------------------------
// 3) Sorting intervals by start time
// -----------------------------------------------------------------------------
void sorting_intervals_by_start() {
    cout << "3) Sorting Intervals by Start Time\n";
    vector<Interval> intervals = {{5, 10}, {1, 3}, {2, 6}, {8, 9}};

    sort(all(intervals), [](const Interval &a, const Interval &b) {
        return a.start < b.start;
    });

    cout << "Intervals sorted by start time:\n";
    for (auto &it : intervals)
        cout << "[" << it.start << "," << it.end << "] ";
    cout << "\n\n";
}

// -----------------------------------------------------------------------------
// 4) Sorting for Coordinate Compression
// -----------------------------------------------------------------------------
void coordinate_compression() {
    cout << "4) Coordinate Compression\n";
    vector<int> arr = {100, 500, 1000, 500, 100};

    vector<int> sorted_arr = arr;
    sort(all(sorted_arr));
    sorted_arr.erase(unique(all(sorted_arr)), sorted_arr.end());

    // Mapping original values to compressed indices
    unordered_map<int, int> compress;
    for (int i = 0; i < sz(sorted_arr); ++i)
        compress[sorted_arr[i]] = i;

    cout << "Original array: ";
    print_vector(arr);

    cout << "Compressed indices: ";
    for (int x : arr) cout << compress[x] << ' ';
    cout << "\n\n";
}

// -----------------------------------------------------------------------------
// 5) Sorting with Prefix Sums
// -----------------------------------------------------------------------------
void sorting_with_prefix_sums() {
    cout << "5) Sorting with Prefix Sums\n";
    vector<int> arr = {5, 2, 3, 8, 1};
    sort(all(arr));  // sort first for cumulative sums

    vector<int> prefix(sz(arr) + 1, 0);
    for (int i = 0; i < sz(arr); ++i)
        prefix[i + 1] = prefix[i] + arr[i];

    cout << "Sorted array: ";
    print_vector(arr);
    cout << "Prefix sums: ";
    print_vector(prefix);
    cout << '\n';
}

// -----------------------------------------------------------------------------
// 6) Sorting Strings by Length or Lexicographically
// -----------------------------------------------------------------------------
void sorting_strings() {
    cout << "6) Sorting Strings\n";
    vector<string> strs = {"banana", "apple", "kiwi", "apricot", "pear"};

    // Lexicographical sorting
    sort(all(strs));
    cout << "Lexicographically sorted: ";
    print_vector(strs);

    // Sorting by length
    sort(all(strs), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    cout << "Sorted by length: ";
    print_vector(strs);
    cout << '\n';
}

// -----------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sorting_before_binary_search();
    sorting_before_greedy();
    sorting_intervals_by_start();
    coordinate_compression();
    sorting_with_prefix_sums();
    sorting_strings();

    return 0;
}
