#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    string str;
    getline(cin,str);
    char temp;
    temp=str[0];
    str[0]=str[4];
    str[4]=temp;
    cout<<str<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) 
    {
        solve();
    }

    return 0;
}