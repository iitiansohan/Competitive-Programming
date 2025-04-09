#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    // vector<int> b(m);
    int b;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b;
    bool flag=true;
    a[0]=min(a[0],b-a[0]);
    for(int i=1;i<n;i++)
    {
        if(min(a[i],b-a[i])>=a[i-1])
        {
            a[i]=min(a[i],b-a[i]);
        }
        else
        {
            a[i]=max(a[i],b-a[i]);
            if(a[i]<a[i-1])
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
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