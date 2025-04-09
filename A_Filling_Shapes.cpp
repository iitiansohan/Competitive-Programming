#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    if(n%2!=0)
    cout<<0<<endl;
    else
    cout<<(int)pow(2,n/2)<<endl;

    return 0;
}