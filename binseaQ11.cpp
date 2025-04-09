//https://codeforces.com/problemset/problem/991/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool checker(int n,int k)
{
    int s1=0,s2=0;
    while(n>0)
    {
        if(n<=k)
        {
            s1+=n;
            n=0;
        }
        else
        {
            s1+=k;
            n-=k;
            s2+=n/10;
            n-=n/10;
        }
        
    }
    if(s1>=s2)
    return true;
    else 
    return false;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int low=1,high=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(checker(n,mid))
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<(high+1);
    return 0;
}