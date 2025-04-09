#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;//to prevent overflow we use this in place of (r+l)/2
        if(arr[m]>x)
        r=m-1;
        else if(arr[m]<x)
        l=m+1;
        else
        ans=m;
    }
    cout<<ans;
}