#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<string> res(t);
    for(int j=0;j<t;j++)
    {
        int n;
        cin>>n;
        vector<string> e(n);
        for(int i=0;i<n;i++)
        cin>>e[i];
        bool flag=true;
        vector<int> sumline(n);
        for(int i=0;i<n;i++)
        {
            string ele=e[i];
            for(int k=0;k<n;k++)
            {
                if(ele[k]=='1')
                sumline[i]++;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(sumline[i]==sumline[i-1]||sumline[i-1]==0||sumline[i]==0)
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
        res[j]="SQUARE";
        else
        res[j]="TRIANGLE";
    }
    for(int i=0;i<t;i++)
    cout<<res[i]<<endl;
    

    return 0;
}