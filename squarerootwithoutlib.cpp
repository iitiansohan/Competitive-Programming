//Finding the squareroot of a number without using any library functions
//decimal binary search
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const ld eps=1e-9;
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    ld low=0,high=n,ans=0;
    cout<<fixed<<setprecision(8);
    while(low<=high+eps)
    {
        ld mid=low+(high-low)/2;
        if(mid*mid<=n)
        {
            ans=mid;
            low=mid+eps;
        }
        else
        high=mid-eps;
    }
    cout<<ans;
    

    return 0;
}