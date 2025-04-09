#include <bits/stdc++.h>
using namespace std;

int main() {
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
            if(a[mid]<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        cout<<ans+1<<endl;
    }
    

    return 0;
}