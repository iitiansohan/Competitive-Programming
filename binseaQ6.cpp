#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int k;
    cin>>k;
    int k1=k;
    int l[k];
    int r[k];
    for (int i = 0; i < k; i++)
    {
        cin>>l[i]>>r[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<k;i++)
    {
        int low=0,high=n-1,ans1=-1,ans2=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]<=r[i])
            {
                ans2=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>=l[i])
            {
                ans1=mid;
                high=mid-1;
                
            }
            else
            {
                low=mid+1;
            }
        }
        if(ans1 == -1 || ans2 == -1 || ans1 > ans2) 
        {
            cout << 0 << " ";
        } 
        else 
        {
            cout << ans2 - ans1 + 1 << " ";
        }

    } 
    return 0;
}