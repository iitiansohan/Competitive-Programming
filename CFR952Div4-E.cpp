#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    int max=0;
    for(int a=1;a<=x;a++)
    {
        for(int b=1;b<=y;b++)
        {
            if(k%(a*b)) continue;
            int c=k/(a*b);
            if((x+1-a)*(y+1-b)*(z+1-c)>max)
            max=(x+1-a)*(y+1-b)*(z+1-c);
        }
    }
    cout<<max<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}