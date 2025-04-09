#include<bits/stdc++.h>
using namespace std;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define setbits(x) __builtin_popcountll((int)x)
#define result(ans) cout<<(ans?"YES":"NO")<<endl;
#define debug cout<<"OK"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define ff first
#define ss second
#define mii map<int,int>
#define printv(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" \n"[i==v.size()-1];
#define scanv(v) for(auto &i:v) cin>>i;
#define pb push_back
#define scantree(v) for(int i=0;i<v.size()-1;i++){int x,y;cin>>x>>y;x--;y--;v[x].pb(y);v[y].pb(x);}
#define all(v) v.begin(),v.end() 
int mod=1000000007;
int mod2=998244353; 
int mpow(int a,int b,int m){
    int x=1;
    while(b>0){
        if(b&1){
            x=(x*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return x;
}
 
int mdiv(int a,int b, int m){
    int bin=mpow(b,m-2,m);
    return (a*bin)%m;
}
 
int fact(int n,int m){
    if(n<=0) return 1;
    return (n*fact(n-1,m))%m;
}
 
int nCr(int n,int r,int m){
    int ans=fact(n,m);
    ans=mdiv(ans,fact(n-r,m),m);
    ans=mdiv(ans,fact(r,m),m);
    return ans;
}
 
int maxv(vi v){
    int mx=v[0];
    for(auto e:v) mx=max(e,mx);
    return mx;
}
int minv(vi v){
    int mn=v[0];
    for(auto e:v) mn=min(e,mn);
    return mn;
}
 
vi prefix(vi v){
    for(int i=1;i<v.size();i++) v[i]+=v[i-1];
    return v;
}
vi suffix(vi v){
    for(int i=v.size()-2;i>=0;i--) v[i]+=v[i+1];
    return v;
}
 
vvi transpose(vvi v){
    vvi t(v[0].size(),vi(v.size()));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            t[j][i]=v[i][j];
        }
    }
    return t;
}
 
 
int sumv(vi v){
    int sum=0;
    for(auto e:v) sum+=e;
    return sum;
}
 
 
int nC2(int n,int m){
    return (n*(n-1)/2)%m;
}
 
int binary(int n){
    if(n==0) return 0;
    return 1+binary(n-(1ll<<(int)log2(n)));
}
 
 
 
int sumn(int n){
    return n*(n+1)/2;
}
 
 

// ------------------------------------------SOLUTION------------------------------------------


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c0=0,c1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        c1++;
    }
    c0=n-c1;
    if(n%2!=0||c0!=c1)
    cout<<-1<<endl;
    else
    {
        deque<char> dq;
        for(int i=0;i<n;i++)
        dq.push_back(s[i]);
        int count=0;
        vector<int> ans;
        while(!dq.empty())
        {
            if(dq.front()!=dq.back())
            {
                count++;
                dq.pop_front();
                dq.pop_back();
            }
            else
            {
                if(dq.front()=='0')
                {
                    ans.push_back(count+dq.size());
                    dq.push_back('0');
                    dq.push_back('1');
                }
                else
                {
                    ans.push_back(count);
                    dq.push_front('1');
                    dq.push_front('0');
                }
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
}

 
 
 



 
int32_t main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}