#include <bits/stdc++.h>
using namespace std;
#define int long long
bool checker(vector<int> &a,int mid,int k)
{
    int cows=1;
    int curr=a[0];
    for(int i=1;i<a.size();i++)
    {
        if((a[i]-curr)>=mid)
        {
            curr=a[i];
            cows++;
        }

    }
    return cows>=k;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    vector<int> stalls(n);
    for(int i=0;i<n;i++)
    cin>>stalls[i];
    int low=1,high=1e9;int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(checker(stalls,mid,k))
        {
            ans=mid;
            low=mid+1;
        }
        else
        high=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}