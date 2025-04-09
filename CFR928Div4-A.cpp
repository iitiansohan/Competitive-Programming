#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<char> res(t);
    for(int i=0;i<t;i++)
    {
        string str;
        cin>>str;
        int c1=0,c2=0;
        for(int j=0;j<str.length();j++)
        {
            if(str[j]=='A')
            c1++;
            else
            c2++;
        }
        if(c1>=c2)
        res[i]='A';
        else
        res[i]='B';
    }
    for(int i=0;i<t;i++)
    cout<<res[i]<<endl;

    return 0;
}