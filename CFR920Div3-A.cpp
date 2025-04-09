#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<int> res (t);
    for(int j=0;j<t;j++)
    {
        pair<int,int> points[4];
        for(int i=0;i<4;i++)
        cin>>points[i].first>>points[i].second;
        int max=0;
        for(int i=1;i<4;i++)
        {
            if(abs(points[0].first-points[i].first)>max)
            {
                max=points[0].first-points[i].first;
                break;
            }
        }
        res[j]=max*max;
    }
    for(int i=0;i<t;i++)
    cout<<res[i]<<endl;
    

    return 0;
}