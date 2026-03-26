#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    // loop up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            // mark all multiples of i starting from i*i
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    // collect all primes
    vector<int> primes;
    for (int i = 2; i <= n; ++i)
        if (is_prime[i]) primes.push_back(i);

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1e7; // 10 million
    auto primes = sieve(N);

    cout << "Total primes up to " << N << ": " << primes.size() << '\n';
    cout << "First 10 primes: ";
    for (int i = 0; i < 10 && i < (int)primes.size(); ++i)
        cout << primes[i] << ' ';
    cout << '\n';
}
