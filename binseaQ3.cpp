/*Given a sorted array and an integer x. Find the index(0-based indexing) of the smallest number which is greater than or equal to x. */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x; cin >> x;
    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(arr[m]<x)
        {
            l=m+1;
        }
        else
        {
            ans=m;
            r=m-1;
        }
    }
    cout<<arr[ans];

}
    
