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
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int low=0,high=0;
        for(int j=0;j<n;j++)
        {
            if(str[j]=='B')
            {
                low=j;
                break;
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            if(str[j]=='B')
            {
                high=j;
                break;
            }
        }
        if(high>=low)
        res[i]=high-low+1;
    }
    for (int i = 0; i < t; i++)
    cout<<res[i]<<endl;
    
    

    return 0;
}