#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    if(k==1)
    {
        bool flag=true;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]<0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    else
    cout<<"YES\n";
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