/*Given a sorted array, which has been left rotated k times.
(eg- initially the array is 1 2 3 4 5.. after 1 left rotation it
becomes 5 1 2 3 4.. now if k=2 ,. the array becomes 4 5 1 2 3.
U are given this array in the question). The task is to find k */
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int l=0,r=n-1,ans=-1;
    while (l<=r)
    {
        int m=l+(r-l)/2;
        if(arr[m]<arr[0])
        {
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans;
    
    

    


    return 0;
}