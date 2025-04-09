//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool checker(int n,int w,int h,int mid)
{
    int n1 = mid / w;
    int n2 = mid / h;
    if(n1 > n && n2>=1) return true;
    if(n2 > n && n1>=1) return true;
    int num =n1 * n2;
    return num >= n;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w,h,n;
    cin>>w>>h>>n;
    int low=1,high=1e15,ans=1e15;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(checker(n,w,h,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<ans<<"\n";

    return 0;
}