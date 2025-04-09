#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    //bob looses when he will be in 1 and alice will be in 1
    //also when he will be in n and alice in n-1
    if(abs(a-b)%2==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
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