#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> movies;


    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.emplace_back(b, a);
    }
    sort(movies.begin(), movies.end());

    int count = 0, last_end_time = 0;
    for (auto &movie : movies) {
        if (movie.second >= last_end_time) {
            count++;
            last_end_time = movie.first; 
        }
    }

    cout << count << endl;
    return 0;
}
