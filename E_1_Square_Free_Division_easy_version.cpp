#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e7;
vector<int> pre(M+1);
void Seive()
{
    for(int i=2;i<=M;i++)
    pre[i]=i;
    pre[1]=-1;
    for(int i=2;i*i<=M;i++)
    {
        if(pre[i]==i)
        {
            for(int j=i*i;j<=M;j+=i)
            {
                if(pre[j]==j)
                pre[j]=i;
            }
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Seive();
    int t;
    cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int segments=1;
        set<int> st;
        // vector<map<int,int>> comp;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            vector<int> pf;
            while(x!=1)
            {
                if(pf.size()==0||pf.back()!=pre[x])
                pf.push_back(pre[x]);
                else
                pf.pop_back();
                x/=pre[x];
            }
            int p=1;
            for(auto num:pf)
            p*=num;
            if(st.find(p)!=st.end())
            {
                segments++;
                st.clear();
            }
            st.insert(p);
        }
        cout<<segments<<endl;
    }
    return 0;
}