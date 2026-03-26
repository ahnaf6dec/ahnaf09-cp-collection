typedef long long ll;
// Most fastest algo
bool isPrime(ll x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    if (x % 3 == 0) return x == 3;
    for (ll i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}
// less faster than before
bool isPrime(ll x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

// Very slow implementation
bool isPrime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i < x; ++i) {
        bool divisible = false;
        for (ll j = 1; j <= i; ++j) { // redundant inner loop → O(n²)
            if (i * j == x) {
                divisible = true;
                break;
            }
        }
        if (divisible) return false;
    }
    return true;
}