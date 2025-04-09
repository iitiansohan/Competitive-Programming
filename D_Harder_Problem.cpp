#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    for(int i=0;i<n;i++){cin>>a[i];}
    vector<bool> used(n+1,false);
        for(int i=0;i<n;i++){
            if(!used[a[i]]){
                used[a[i]] = true;
                b.push_back(a[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(!used[i]) b.push_back(i);
        }
        for(int i=0;i<n;i++) cout<<b[i]<<" ";
        cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}