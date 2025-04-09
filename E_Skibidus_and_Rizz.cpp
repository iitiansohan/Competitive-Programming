#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    string s="";
    if(k<abs(n-m)||k>max(n,m))
    {
        cout<<-1<<endl;
        return;
    }

    if(n>=m)
    {
        for(int i=1;i<=k;i++)
        s+="0";
        n=n-k;
        for(int i=1;i<=min(n,m);i++)
        s+="10";
        int a=min(n,m);
        n-=a;
        m-=a;
        for(int i=1;i<=n;i++)
        s+="0";
        for(int i=1;i<=m;i++)
        s+="1";
        cout<<s<<endl;
    }
    else
    {
        for(int i=1;i<=k;i++)
        s+="1";
        m=m-k;
        for(int i=1;i<=min(n,m);i++)
        s+="01";
        int a=min(n,m);
        n-=a;
        m-=a;
        for(int i=1;i<=n;i++)
        s+="0";
        for(int i=1;i<=m;i++)
        s+="1";
        cout<<s<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}