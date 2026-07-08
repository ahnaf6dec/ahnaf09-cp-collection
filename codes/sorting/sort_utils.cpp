#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using ll = long long;

// -----------------------------------------------------------------------------
// Utility helper: Print container (for demos)
template <class Container>
void printc(const Container &c, const string &sep = " ") {
  bool first = true;
  for (const auto &v : c) {
    if (!first) cout << sep;
    cout << v;
    first = false;
  }
  cout << '\n';
}

// Print vector of pairs (for clarity)
template <class T1, class T2>
void print_pairs(const vector<pair<T1, T2>> &v) {
  for (auto &p : v) cout << "(" << p.first << "," << p.second << ") ";
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 1) stable_sort() with multi-key comparator example
void demo_stable_sort() {
  cout << "demo_stable_sort:\n";
  vector<pair<int, string>> v = {
      {3, "apple"}, {1, "banana"}, {3, "cherry"}, {2, "date"}, {1, "apricot"} };

  cout << "Before stable_sort (original order):\n";
  for (auto &p : v) cout << p.first << ' ' << p.second << '\n';

  // Sort by first key only but preserve original order for equal keys.
  stable_sort(all(v), [](const auto &a, const auto &b) {
    return a.first < b.first;
  });

  cout << "After stable_sort by first key (stable preserves relative order):\n";
  for (auto &p : v) cout << p.first << ' ' << p.second << '\n';
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 2) is_sorted() and is_sorted_until()
void demo_is_sorted() {
  cout << "demo_is_sorted / is_sorted_until:\n";
  vector<int> a = {1, 2, 3, 5, 4, 6, 7};
  cout << "Sequence: ";
  printc(a);

  cout << "is_sorted? " << boolalpha << is_sorted(all(a)) << '\n';

  auto it = is_sorted_until(all(a));
  cout << "first unsorted index: " << distance(a.begin(), it) << '\n';
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 3) partial_sort() and partial_sort_copy()
void demo_partial_sort() {
  cout << "demo_partial_sort / partial_sort_copy:\n";
  vector<int> a = {9, 1, 5, 2, 7, 3, 8, 6, 4};
  int K = 4;

  vector<int> b = a;                 // copy for demonstration
  partial_sort(b.begin(), b.begin() + K, b.end());
  cout << "First " << K << " smallest elements sorted (partial_sort):\n";
  for (int i = 0; i < K; ++i) cout << b[i] << ' ';
  cout << '\n';

  vector<int> dest(K);
  partial_sort_copy(all(a), dest.begin(), dest.end()); // returns top K sorted
  cout << "partial_sort_copy result (K smallest sorted): ";
  printc(dest);
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 4) nth_element() — median / k-th element usage
void demo_nth_element() {
  cout << "demo_nth_element:\n";
  vector<int> a = {7, 2, 1, 8, 6, 3, 5, 4};
  cout << "Original: ";
  printc(a);

  int n = sz(a);
  int k = n / 2; // median index (0-based)
  nth_element(a.begin(), a.begin() + k, a.end()); // average O(n)
  cout << "Element at median position after nth_element: " << a[k] << '\n';

  // To get the k-th smallest sorted value, you can copy and sort prefix:
  vector<int> copyv = a;
  nth_element(copyv.begin(), copyv.begin() + 2, copyv.end()); // 3rd smallest in place
  // Elements before index 2 are <= copyv[2], but not sorted. Sort if ordered output needed:
  sort(copyv.begin(), copyv.begin() + 3);
  cout << "3 smallest elements (sorted): ";
  printc(vector<int>(copyv.begin(), copyv.begin() + 3));
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 5) sort + unique to remove duplicates (simple & efficient)
void demo_unique_sort() {
  cout << "demo_unique_sort (sort + unique):\n";
  vector<int> a = {4, 2, 2, 1, 3, 1, 4, 3, 3};
  cout << "Original: ";
  printc(a);

  sort(all(a));
  a.erase(unique(all(a)), a.end());
  cout << "After sort + unique: ";
  printc(a);
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 6) Remove duplicates while preserving original order
template <class T>
vector<T> remove_duplicates_preserve_order(const vector<T> &v) {
  unordered_set<T> seen;
  vector<T> res;
  res.reserve(v.size());
  for (const T &x : v) {
    if (seen.insert(x).second) res.push_back(x);
  }
  return res;
}

void demo_remove_duplicates_preserve_order() {
  cout << "demo_remove_duplicates_preserve_order:\n";
  vector<int> a = {4, 2, 2, 1, 3, 1, 4, 3, 3};
  auto out = remove_duplicates_preserve_order(a);
  printc(out);
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 7) lower_bound, upper_bound, binary_search examples
void demo_binary_search_bounds() {
  cout << "demo_lower_upper_binary_search:\n";
  vector<int> a = {1, 2, 3, 5, 5, 5, 7, 9};
  cout << "Array: ";
  printc(a);

  int x = 5;
  auto lb = lower_bound(all(a), x) - a.begin(); // first >= x
  auto ub = upper_bound(all(a), x) - a.begin(); // first > x

  cout << "lower_bound(5): index " << lb << '\n';
  cout << "upper_bound(5): index " << ub << '\n';
  cout << "count of 5: " << (ub - lb) << '\n';
  cout << "binary_search(6): " << boolalpha << binary_search(all(a), 6) << '\n';
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 8) merge and inplace_merge
void demo_merge_inplace_merge() {
  cout << "demo_merge / inplace_merge:\n";
  vector<int> a = {1, 3, 5};
  vector<int> b = {2, 4, 6, 8};
  vector<int> merged;
  merged.reserve(sz(a) + sz(b));
  merge(all(a), all(b), back_inserter(merged));
  cout << "Merged into new container: ";
  printc(merged);

  // inplace_merge: requires two consecutive sorted ranges in the same container
  vector<int> c = {1, 4, 7, 2, 3, 9}; // first range [0,3) sorted, second [3,6) sorted? not here
  // For meaningful demo, create a container with two sorted halves:
  vector<int> d = {1, 4, 7, 10,   2, 3, 6, 8};
  cout << "Before inplace_merge: ";
  printc(d);
  inplace_merge(d.begin(), d.begin() + 4, d.end());
  cout << "After inplace_merge: ";
  printc(d);
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 9) top-k using priority_queue (max-heap and min-heap)
void demo_top_k_priority_queue() {
  cout << "demo_top_k_priority_queue:\n";
  vector<int> a = {5, 1, 9, 2, 8, 3, 7, 4};
  int K = 3;

  // Max-heap: default priority_queue - top is largest
  priority_queue<int> maxh(all(a));
  cout << "Top " << K << " (max-heap): ";
  for (int i = 0; i < K && !maxh.empty(); ++i) {
    cout << maxh.top() << ' ';
    maxh.pop();
  }
  cout << '\n';

  // Min-heap to keep K largest elements efficiently:
  priority_queue<int, vector<int>, greater<int>> minh;
  for (int x : a) {
    minh.push(x);
    if (sz(minh) > K) minh.pop(); // keep only K largest in min-heap
  }
  vector<int> topk;
  while (!minh.empty()) { topk.push_back(minh.top()); minh.pop(); }
  reverse(all(topk)); // now in descending order
  cout << "Top " << K << " largest (kept via min-heap): ";
  printc(topk);
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 10) Counting sort (for small integer ranges) — stable variant
vector<int> counting_sort(const vector<int> &a, int minV, int maxV) {
  if (a.empty()) return {};
  int range = maxV - minV + 1;
  vector<int> cnt(range);
  for (int x : a) ++cnt[x - minV];

  // prefix sums (stable)
  for (int i = 1; i < range; ++i) cnt[i] += cnt[i - 1];

  vector<int> out(a.size());
  for (int i = (int)a.size() - 1; i >= 0; --i) { // iterate backwards for stability
    int x = a[i];
    int idx = --cnt[x - minV];
    out[idx] = x;
  }
  return out;
}

void demo_counting_sort() {
  cout << "demo_counting_sort:\n";
  vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6, 5};
  int minV = 0, maxV = 9;
  auto sorted = counting_sort(a, minV, maxV);
  cout << "Counting-sorted result: ";
  printc(sorted);
  cout << '\n';
}

// -----------------------------------------------------------------------------
// 11) Useful small templates: sort indices by values, comparator by multiple keys
template <class T>
vector<int> sort_indices_by_value(const vector<T> &a, bool ascending = true) {
  int n = sz(a);
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  if (ascending) {
    sort(all(idx), [&](int i, int j) { return a[i] < a[j]; });
  } else {
    sort(all(idx), [&](int i, int j) { return a[i] > a[j]; });
  }
  return idx;
}

void demo_sort_indices() {
  cout << "demo_sort_indices_by_value:\n";
  vector<int> a = {30, 10, 20, 40};
  auto idx = sort_indices_by_value(a);
  cout << "Indices by ascending value: ";
  printc(idx);
  cout << "Values in that order: ";
  for (int i : idx) cout << a[i] << ' ';
  cout << '\n' << '\n';
}

// -----------------------------------------------------------------------------
// 12) Combined demonstration runner
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << "STL Sorting & Searching Utilities Demo\n";
  cout << "======================================\n\n";

  demo_stable_sort();
  demo_is_sorted();
  demo_partial_sort();
  demo_nth_element();
  demo_unique_sort();
  demo_remove_duplicates_preserve_order();
  demo_binary_search_bounds();
  demo_merge_inplace_merge();
  demo_top_k_priority_queue();
  demo_counting_sort();
  demo_sort_indices();

  cout << "End of demo.\n";
  return 0;
}
