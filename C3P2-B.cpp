#include <bits/stdc++.h>
using namespace std;

#define int long long

// Sieve to precompute primes
vector<int> sieve(int n) {
    vector<int> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}

// Function to check if a number has exactly two distinct prime divisors
bool solve(int x, const vector<int>& primes) {
    int count = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0 && primes[i]) {
            count++;
            // Skip all multiples of this prime factor
            while (x % i == 0) x /= i;
        }
    }
    // If there's any prime factor greater than sqrt(x), it should be counted
    if (x > 1 && primes[x]) count++;

    return count == 2;  // True if exactly two distinct prime divisors
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Precompute primes using Sieve of Eratosthenes
    vector<int> primes = sieve(n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (solve(i, primes)) {
            ans++;
        }
    }

    cout << ans << endl;
}
