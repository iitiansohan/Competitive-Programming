#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll mulmod(ll a, ll b) {
    return (a * b) % MOD;
}

ll powmod(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            result = mulmod(result, base);
        base = mulmod(base, base);
        exp >>= 1;
    }
    return result;
}

map<ll, ll> getPrimeFactors(ll n) {
    map<ll, ll> factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

ll solveForNumber(ll x, ll k, ll n) {
    map<ll, ll> primeFactors = getPrimeFactors(x);

    for (map<ll, ll>::iterator it = primeFactors.begin(); it != primeFactors.end(); ++it) {
        if (it->first > k) return 0;
    }

    ll result = 0;
    ll maxLen = 0;
    for (map<ll, ll>::iterator it = primeFactors.begin(); it != primeFactors.end(); ++it) {
        maxLen += it->second;
    }
    maxLen = min(n, maxLen);

    for (ll len = 1; len <= maxLen; len++) {
        ll ways = powmod(k - 1, len - 1);
        result = (result + ways) % MOD;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll k, n;
        cin >> k >> n;

        for (ll x = 1; x <= k; x++) {
            cout << solveForNumber(x, k, n);
            if (x < k) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
