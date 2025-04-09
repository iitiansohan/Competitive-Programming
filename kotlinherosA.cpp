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
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin>>d[i];
        }
        sort(d.begin(),d.end());
        if(d[n-1]-d[n-2]==1)
        res[i]=d[n-2];
        else
        res[i]=-1;  
    }
    for(int i=0;i<t;i++)
    {
        if(res[i]==-1)
        cout<<"Ambiguous"<<endl;
        else
        cout<<res[i]<<endl;
    }
    

    return 0;
}