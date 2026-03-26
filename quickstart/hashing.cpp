#include <bits/stdc++.h>
using namespace std;

/*
====================================================
 CF FREQUENCY ARRAY & HASHING TEMPLATE
 Author: Ahnaf
 Usage: Competitive Programming (Codeforces)
====================================================
*/

// -------- FAST IO --------
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)

// -------- TYPE ALIASES --------
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

// -------- CONSTANTS --------
const int INF = 1e9;
const ll LINF = 1e18;
const int MAXA = 1e5 + 5;   // adjust according to constraints

// freq array
int freq[MAXA];

void use_frequency_array(vector<int>& a) {
    // reset only required range if possible
    memset(freq, 0, sizeof(freq));

    for(int x : a) freq[x]++;

    // example usage
    for(int i = 0; i < MAXA; i++) {
        if(freq[i] > 0) {
            // i occurs freq[i] times
        }
    }
}

// unordered map -> O(n^2)
void use_unordered_map(vector<int>& a) {
    unordered_map<int,int> mp;
    mp.reserve(a.size() * 2);
    mp.max_load_factor(0.25);

    for(int x : a) mp[x]++;

    for(auto &it : mp) {
        int key = it.first;
        int cnt = it.second;
    }
}

// ====================================================
// ORDERED MAP (WHEN SORTING / BOUNDS NEEDED)
// ====================================================

void use_ordered_map(vector<int>& a) {
    map<int,int> mp;

    for(int x : a) mp[x]++;

    // keys are sorted
    for(auto &it : mp) {
        int key = it.first;
        int cnt = it.second;
    }

    // lower_bound / upper_bound supported
    auto it = mp.lower_bound(5);
}

// ====================================================
// CHARACTER FREQUENCY
// ====================================================

void char_frequency(const string& s) {
    int cnt[26] = {0};
    for(char c : s) cnt[c - 'a']++;
}

// ====================================================
// 5️⃣ COMMON CF PATTERNS
// ====================================================

// Check if all elements are unique
bool all_unique(vector<int>& a) {
    unordered_set<int> st;
    for(int x : a) {
        if(st.count(x)) return false;
        st.insert(x);
    }
    return true;
}

// Find element with max frequency
int max_frequency_element(vector<int>& a) {
    unordered_map<int,int> mp;
    int mx = 0, val = -1;
    for(int x : a) {
        if(++mp[x] > mx) {
            mx = mp[x];
            val = x;
        }
    }
    return val;
}

// ====================================================
// ADVANCED & VERY COMMON CF HASHING UTILITIES
// ====================================================

// Count pairs (i < j) such that a[i] == a[j]
ll count_equal_pairs(const vector<int>& a) {
    unordered_map<int,ll> mp;
    ll ans = 0;
    for(int x : a) {
        ans += mp[x];
        mp[x]++;
    }
    return ans;
}

// Check if any element appears at least k times
bool appears_at_least_k(const vector<int>& a, int k) {
    unordered_map<int,int> mp;
    for(int x : a) {
        if(++mp[x] >= k) return true;
    }
    return false;
}

// Get frequency map from array
unordered_map<int,int> get_freq_map(const vector<int>& a) {
    unordered_map<int,int> mp;
    for(int x : a) mp[x]++;
    return mp;
}

// Coordinate Compression (VERY IMPORTANT)
vector<int> compress(vector<int> a) {
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int &x : a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }
    return a;
}

// Check if two arrays are anagrams (same frequency)
bool same_frequency(vector<int>& a, vector<int>& b) {
    if(a.size() != b.size()) return false;
    unordered_map<int,int> mp;
    for(int x : a) mp[x]++;
    for(int x : b) {
        if(--mp[x] < 0) return false;
    }
    return true;
}

// ====================================================
// PREFIX HASHING / SUBARRAY TECHNIQUES
// ====================================================

// Count subarrays with sum = k
ll subarray_sum_k(const vector<int>& a, int k) {
    unordered_map<ll,ll> mp;
    mp[0] = 1;
    ll sum = 0, ans = 0;
    for(int x : a) {
        sum += x;
        ans += mp[sum - k];
        mp[sum]++;
    }
    return ans;
}

// Longest subarray with sum = k
int longest_subarray_sum_k(const vector<int>& a, int k) {
    unordered_map<ll,int> first;
    ll sum = 0;
    int ans = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        sum += a[i];
        if(sum == k) ans = i + 1;
        if(!first.count(sum)) first[sum] = i;
        if(first.count(sum - k))
            ans = max(ans, i - first[sum - k]);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Choose ONE based on constraints
    // use_frequency_array(a);
    // use_unordered_map(a);
    // use_ordered_map(a);
}

int main() {
    fastio;

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}

