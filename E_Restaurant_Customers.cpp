#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arrivals(n), departures(n);
    for (int i = 0; i < n; i++) {
        cin >> arrivals[i] >> departures[i];
    }
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    int current_customers = 0, max_customers = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arrivals[i] < departures[j]) {
            current_customers++;
            max_customers = max(max_customers, current_customers);
            i++;
        } else {
            current_customers--;
            j++;
        }
    }

    cout << max_customers << endl;
    return 0;
}
