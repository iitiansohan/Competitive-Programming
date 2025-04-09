#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char ch[k];
    for(int i=0;i<k;i++)
    cin>>ch[i];
    int count=0;
    set<char> st;
    for(int i=0;i<n;i++)
    {
        st.insert(s[i]);
    }
    
    

    return 0;
}