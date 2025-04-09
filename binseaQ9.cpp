//https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool checker(vector<int>tree,int M,int H)
{
    int sum=0;
    for(int i=0;i<tree.size();i++)
    {
        if(tree[i]>H)
        sum+=tree[i]-H;
        else
        continue;
    }
    return sum>=M;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    //n is within 1e6
    //m is within 2e9
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int low=0,high=2e9,ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(checker(arr,m,mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    
    

    return 0;
}