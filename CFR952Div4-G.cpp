#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD= 1e9+7;
int binExp(int base, int exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod; 
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
void solve() {
    int l,r,k;
    cin>>l>>r>>k;
    int a=binExp((9/k+1),r,MOD);
    int b=binExp((9/k+1),l,MOD);
    int ans=(a-b+MOD)%MOD;
    cout<<ans<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}