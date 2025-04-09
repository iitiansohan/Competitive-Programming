#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(n%2==0)
    {
        int ans;
        ans=n/(k-1);
        n=n%(k-1);
        if(n==0)
        cout<<ans<<endl;
        else
        cout<<++ans<<endl;
    }
    else
    {
        if(n<=k)
        cout<<1<<endl;
        else
        {
            n=n-k;
            int ans=1;
            ans+=n/(k-1);
            n=n%(k-1);
            if(n==0)
            cout<<ans<<endl;
            else
            cout<<++ans<<endl;
        }
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