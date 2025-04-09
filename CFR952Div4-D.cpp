#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n,m;
    cin>>n>>m;
    string str[n];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    int maxr=-1,maxc=-1,max=0;
    for(int i=0;i<n;i++)
    {
        string s=str[i];
        int count=0;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='#')
            count++;
        }
        if(count>max)
        {
            max=count;
            maxr=i;
        }
    }
    max=0;
    for(int i=0;i<m;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(str[j][i]=='#')
            count++;
        }
        if(count>max)
        {
            max=count;
            maxc=i;
        }
    }
    cout<<(maxr+1)<<" "<<(maxc+1)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }

    return 0;
}