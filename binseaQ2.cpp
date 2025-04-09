/*Given a binary string(char containing only 0 and 1s) where all zeros occur before all 1s(eg-001111).
Find the index(0-based indexing) of the left-most 1.If there is no 1 present in the given string , print -1. */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(s[m]=='1')
        {
            ans=m;
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    cout<<ans;
    
    
}