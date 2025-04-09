#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    int remt=k%n;
    int cycle=0;
    int count=0,ans=0;
    bool counter=false;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        cycle--;
        else
        cycle++;
        count++;
        if(cycle==-x)
        {
            counter=true;
            break;
        }     
    }
    if(count>k||counter==false)
    {
        cout<<0<<endl;
        return;
    }
    if(count==k)
    {
        cout<<1<<endl;
        return;
    }
    ans++;
    k=k-count;
    cycle=0,count=0;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        cycle--;
        else
        cycle++;
        count++;
        if(cycle==0)
        {
            flag=true;
            break;
            
        }     
    }
    if(!flag)
    {
        cout<<ans<<endl;
        return;
    }
    ans+=k/count;
    cout<<ans<<endl;


    
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}