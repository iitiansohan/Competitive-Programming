#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') c++;
    }
    cout<<c<<endl;
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