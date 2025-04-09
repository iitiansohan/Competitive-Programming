#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n+1);
    if(k%2==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==n)
            {
                a[i]=n-1;
            }
            else
            a[i]=n;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(i==n-1)
            a[i]=n;
            else
            a[i]=n-1;

        }
    }
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
