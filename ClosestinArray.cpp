#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x; cin>> n>> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    sort(a.begin(),a.end());
    int low=0,high=n-1,ans1=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(x<=a[mid])
        {
            high=mid-1;
            ans1=mid;
        }
        else 
        low=mid+1;
    }
    low=0,high=n-1;
    int ans2=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(x>=a[mid])
        {
            low=mid+1;
            ans2=mid;
        }
        else
        high=mid-1;
    }
    if(a[ans1]==a[ans2])
    cout<<a[ans1]<<endl;
    else
    {
        int key1=abs(x-a[ans1]);
        int key2=abs(x-a[ans2]);
        if(key1<key2) cout<<a[ans1]<<endl;
        else cout<<a[ans2]<<endl;
    }


    return 0;
}