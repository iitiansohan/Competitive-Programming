#include <bits/stdc++.h>
using namespace std;
#define int long long
bool checker(vector<int> &a,int k,int maxsum)
{
    int currsum=0;
    int segments=1;
    for(int i=0;i<a.size();i++)
    {
        currsum+=a[i];
        if(currsum>maxsum)
        {
            currsum=a[i];
            segments++;
        }
    }
    return segments<=k;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int low=*max_element(a.begin(),a.end()),high=accumulate(a.begin(),a.end(),0ll);
    int ans=high;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(checker(a,k,mid))
        {
            high=mid-1;
            ans=mid;
        }
        else
        low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}