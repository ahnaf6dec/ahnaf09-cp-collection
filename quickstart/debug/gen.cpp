// g++ gen.cpp -O2 -std=gnu++20 -o gen && ./gen

#include <bits/stdc++.h>
using namespace std;

/* ================= RANDOM ================= */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd_ll(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}

int rnd_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

double rnd_double(double l, double r) {
  return uniform_real_distribution<double>(l, r)(rng);
}

/* ================= GENERATORS ================= */

vector<long long> gen_array_ll(int n, long long l, long long r) {
  vector<long long> a(n);
  for (auto &x : a) x = rnd_ll(l, r);
  return a;
}

vector<int> gen_array_int(int n, int l, int r) {
  vector<int> a(n);
  for (auto &x : a) x = rnd_int(l, r);
  return a;
}

vector<double> gen_array_double(int n, double l, double r) {
  vector<double> a(n);
  for (auto &x : a) x = rnd_double(l, r);
  return a;
}

vector<int> gen_permutation(int n) {
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  shuffle(p.begin(), p.end(), rng);
  return p;
}

string gen_string(int n, char l, char r) {
  string s;
  for (int i = 0; i < n; i++) s += char(rnd_int(l, r));
  return s;
}

vector<vector<long long>> gen_matrix(int n, int m, long long l, long long r) {
  vector<vector<long long>> a(n, vector<long long>(m));
  for (auto &row : a)
    for (auto &x : row) x = rnd_ll(l, r);
  return a;
}

vector<pair<int, int>> gen_tree(int n) {
  vector<pair<int, int>> edges;
  for (int i = 2; i <= n; i++) edges.push_back({rnd_int(1, i - 1), i});
  shuffle(edges.begin(), edges.end(), rng);
  return edges;
}

vector<pair<int, int>> gen_graph(int n, int m) {
  set<pair<int, int>> edges;
  while ((int)edges.size() < m) {
    int u = rnd_int(1, n), v = rnd_int(1, n);
    if (u == v) continue;
    if (u > v) swap(u, v);
    edges.insert({u, v});
  }
  return vector<pair<int, int>>(edges.begin(), edges.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int type;
    cin >> type;
    if (type == 0) break;

    /* ---------- SINGLE NUMBER ---------- */
    if (type == 1) {
      cerr << "1=int 2=long long 3=double : ";
      int t;
      cin >> t;

      if (t == 1) {
        int l, r;
        cin >> l >> r;
        cout << rnd_int(l, r) << "\n";
      } else if (t == 2) {
        long long l, r;
        cin >> l >> r;
        cout << rnd_ll(l, r) << "\n";
      } else {
        double l, r;
        cin >> l >> r;
        cout << fixed << setprecision(6) << rnd_double(l, r) << "\n";
      }
    }

    /* ---------- MULTIPLE NUMBERS ---------- */
    else if (type == 2) {
      int k;
      cin >> k;
      for (int i = 0; i < k; i++) {
        int t = rnd_int(1, 3);
        if (t == 1)
          cout << rnd_int(-100, 100) << " ";
        else if (t == 2)
          cout << rnd_ll(-1e9, 1e9) << " ";
        else
          cout << fixed << setprecision(3) << rnd_double(-100, 100) << " ";
      }
      cout << "\n";
    }

    /* ---------- ARRAY ---------- */
    else if (type == 3) {
      int n;
      cin >> n;
      long long l, r;
      cin >> l >> r;
      auto a = gen_array_ll(n, l, r);
      cout << n << "\n";
      for (auto x : a) cout << x << " ";
      cout << "\n";
    }

    /* ---------- PERMUTATION ---------- */
    else if (type == 4) {
      int n;
      cin >> n;
      auto p = gen_permutation(n);
      cout << n << "\n";
      for (int x : p) cout << x << " ";
      cout << "\n";
    }

    /* ---------- STRING ---------- */
    else if (type == 5) {
      int n;
      cin >> n;
      cerr << "1=lower 2=upper 3=binary: ";
      int t;
      cin >> t;
      if (t == 1)
        cout << gen_string(n, 'a', 'z') << "\n";
      else if (t == 2)
        cout << gen_string(n, 'A', 'Z') << "\n";
      else
        cout << gen_string(n, '0', '1') << "\n";
    }

    /* ---------- MATRIX ---------- */
    else if (type == 6) {
      int n, m;
      cin >> n >> m;
      long long l, r;
      cin >> l >> r;
      auto mat = gen_matrix(n, m, l, r);
      cout << n << " " << m << "\n";
      for (auto &row : mat) {
        for (auto x : row) cout << x << " ";
        cout << "\n";
      }
    }

    /* ---------- TREE ---------- */
    else if (type == 7) {
      int n;
      cin >> n;
      cout << n << "\n";
      for (auto [u, v] : gen_tree(n)) cout << u << " " << v << "\n";
    }

    /* ---------- GRAPH ---------- */
    else if (type == 8) {
      int n, m;
      cin >> n >> m;
      cout << n << " " << m << "\n";
      for (auto [u, v] : gen_graph(n, m)) cout << u << " " << v << "\n";
    }

    /* ---------- QUERIES ---------- */
    else if (type == 9) {
      int q, n;
      cin >> q >> n;
      cout << q << "\n";
      while (q--) {
        int t = rnd_int(1, 3);
        int l = rnd_int(1, n);
        int r = rnd_int(l, n);
        cout << t << " " << l << " " << r << "\n";
      }
    }

    /* ---------- ARRAY + QUERIES ---------- */
    else if (type == 10) {
      int n, q;
      cin >> n >> q;
      auto a = gen_array_ll(n, -1e9, 1e9);
      cout << n << " " << q << "\n";
      for (auto x : a) cout << x << " ";
      cout << "\n";
      while (q--) {
        int t = rnd_int(1, 2);
        int i = rnd_int(1, n);
        long long v = rnd_ll(-1e9, 1e9);
        cout << t << " " << i << " " << v << "\n";
      }
    }
  }
  return 0;
}
