#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(k--)
    {
        int x;
        cin>>x;
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(a[mid]>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        if(ans==-1)
        cout<<n+1<<endl;
        else
        cout<<ans+1<<endl;
    }
    return 0;
}