#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

// Function to find the Pisano period and count Fibonacci numbers divisible by k
pair<long long, vector<long long>> pisano_period(long long k) {
    long long a = 0, b = 1;
    vector<long long> indices; // To store indices of Fibonacci numbers divisible by k

    for (long long i = 0; ; i++) {
        if (a % k == 0) {
            indices.push_back(i + 1); // Store 1-based index
        }
        long long c = (a + b) % k;
        a = b;
        b = c;

        // Check for the start of a new period
        if (a == 0 && b == 1) {
            break;
        }
    }

    return {indices.size(), indices}; // Return the count and indices
}

// Function to find the n-th Fibonacci number divisible by k
long long get_nth_divisible_fibonacci(long long n, long long k) {
    auto [count_divisible, divisible_indices] = pisano_period(k);

    // If there are no Fibonacci numbers divisible by k
    if (count_divisible == 0) {
        return 0; // or some other indication of failure
    }

    // Find the full cycles in n
    long long full_cycles = (n - 1) / count_divisible; // Complete cycles of divisible numbers
    long long index_in_cycle = (n - 1) % count_divisible; // Index in the current cycle

    // Calculate the result index in the sequence of Fibonacci numbers
    long long result_index = full_cycles * (count_divisible + 1) + divisible_indices[index_in_cycle];

    // We can calculate the Fibonacci number directly using fast doubling method
    long long fib1 = 0, fib2 = 1;

    for (long long i = 2; i <= result_index; ++i) {
        long long fib_next = (fib1 + fib2) % MOD;
        fib1 = fib2;
        fib2 = fib_next;
    }

    return fib2; // This is f(result_index) % MOD
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long result = get_nth_divisible_fibonacci(n, k);
        cout << result << endl;
    }

    return 0;
}
