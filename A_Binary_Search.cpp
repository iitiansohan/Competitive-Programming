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
            if(x<a[mid])
            high=mid-1;
            else if(x>a[mid])
            low=mid+1;
            else
            {
                ans=mid;
                break;
            }
        }
        if(ans==-1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }

    return 0;
}