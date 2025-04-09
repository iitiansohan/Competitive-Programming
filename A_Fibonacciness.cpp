#include <bits/stdc++.h>
using namespace std;

void sohan() {
    int a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a4>>a5;
    int max_fibonacciness = 0;
    vector<int> candidates = {a1 + a2, a4 - a2, a5 - a4};
    
    for (int a3 : candidates) {
        int fib_count = 0;
        if (a3 == a1 + a2) fib_count++;
        if (a4 == a2 + a3) fib_count++;
        if (a5 == a3 + a4) fib_count++;
        max_fibonacciness = max(max_fibonacciness, fib_count);
    }

    cout << max_fibonacciness << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        sohan();
    }

    return 0;
}