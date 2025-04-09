#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    int count=0;
    while(l<r)
    {
        if((a[l]+a[r])<=x)
        {
            count++;
            l++;
            r--;
        }
        else
        {
            r--;
        }
    }
    int key=max(0ll,n-count*2);
    int ans=key+count;
    cout<<ans<<endl;

    

    return 0;
}