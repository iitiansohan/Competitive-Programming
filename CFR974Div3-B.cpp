#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    int s=n-k+1,e=n;
    int t=0;
    if(s%2==1) t=(e-s)/2+1;
    else t=(e-s+1)/2;
    if(t%2==0) cout<<"YES\n";
    else cout<<"NO\n";
} 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}