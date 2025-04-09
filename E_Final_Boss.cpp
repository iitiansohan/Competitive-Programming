#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int h, n;
    cin >> h >> n;

    vector<int> A(n), C(n);

    for (int &i : A)
        cin >> i;
    for (int &i : C)
        cin >> i;
    
    auto chk = [&](int t){
        int dmg = 0;
        for (int i = 0; i < n and dmg < h; i++){
            int cnt = (t - 1) / C[i] + 1;

            if (cnt >= h)
                return true;

            dmg += cnt * A[i];
        }
        return dmg >= h;
    };

    int L = 1, H = 1e12;

    while (L < H){
        int M = (L + H) / 2;
        chk(M) ? H = M : L = M + 1;
    }
    cout << L << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc;
    cin >> tc;

    while (tc--)
    solve();
}