#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int c=0;
    int c1=0,c0=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        c1++;
        else
        c0++;
    }
    for(int i=0;i<n;i++)
    {
        if((s[i]=='1'&&c0==0)||(s[i]=='0'&&c1==0))
        break;
        if(s[i]=='1')
        c0--;
        else
        c1--;
        c++;
    }
    cout<<(n-c)<<endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}