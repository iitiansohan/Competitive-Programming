#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int> b(m);
    for(int i=0;i<m;i++)
    cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=0;
    int p1=0,p2=0;
    while(p1<n&&p2<m)
    {
        if(a[p1]>k+b[p2])
        p2++;
        else if(a[p1]<b[p2]-k)
        p1++;
        else
        {
            p1++;
            p2++;
            ans++;
        }
    }
    cout<<ans<<endl;

    

    return 0;
}