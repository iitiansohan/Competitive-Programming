#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<int> res(t);
    cout<<fixed<<setprecision(8);
    for(int i=0;i<t;i++)
    {
        int x,y,k;
        cin>>x>>y>>k;
        int s1=(x+k-1)/k,s2=(y+k-1)/k;
        if(s1>s2)
        {
            res[i]=2*s1-1;
        }
        else
        {
            res[i]=2*s2;
        }
    }
    for(int i=0;i<t;i++)
    cout<<res[i]<<endl;
    

    return 0;
}