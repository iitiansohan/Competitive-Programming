#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
        int a[n],b[n],dif[n]{};
        for(int& i:a)cin>>i;
        long long total_diff = 0, pls=0;
        for(int i=0;i<n;i++) {
            cin>>b[i];
            dif[i]=b[i]-a[i];
            if(dif[i]>0) total_diff += dif[i];
            else pls += dif[i];
        }
        bool ok=true;
        for(int i=0;i<n;i++) 
        {
            if(dif[i]>0) {
                if(a[i]-total_diff+2*dif[i]<b[i]) 
                {
                    ok=false;
                    break;
                }
                
            } 
            else {
                if(a[i]-total_diff < b[i]) 
                {
                    ok=false;
                    break;
                }
            }
        }
        if(ok)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
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