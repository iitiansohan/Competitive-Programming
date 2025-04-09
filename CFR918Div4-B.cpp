#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str[3];
    for(int i=0;i<3;i++)
    cin>>str[i];
    for(int i=0;i<3;i++)
    {
        bool flag1=false,flag2=false,flag3=false;
        string s=str[i];
        for(int j=0;j<3;j++)
        {
            if(s[j]=='A')
            flag1=true;
            if(s[j]=='B')
            flag2=true;
            if(s[j]=='C')
            flag3=true;
        }
        if(!flag1)
        cout<<"A"<<endl;
        if(!flag2)
        cout<<"B"<<endl;
        if(!flag3)
        cout<<"C"<<endl;
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