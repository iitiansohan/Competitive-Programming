#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    set<int> st;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(st.find(x)==st.end())
        {
            count++;
            st.insert(x);
        }    
    }
    cout<<count<<endl;   
    return 0;
}