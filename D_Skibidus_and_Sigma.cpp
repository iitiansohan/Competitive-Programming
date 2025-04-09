#include <bits/stdc++.h>
using namespace std;
#define int long long
bool customComparator(const vector<int>& a, const vector<int>& b) {
    int sumA = accumulate(a.begin(), a.end(), 0);
    int sumB = accumulate(b.begin(), b.end(), 0);
    return sumA > sumB;  
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
    }
    sort(arr.begin(),arr.end(),customComparator);
    int cpy[n*m];
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cpy[c++]=arr[i][j];
    }
    int pre[n*m];
    pre[0]=cpy[0];
    for(int i=1;i<n*m;i++)
    {
        pre[i]=pre[i-1]+cpy[i];
    }
    int sum=0;
    for(int i=0;i<n*m;i++)
    sum+=pre[i];
    cout<<sum<<endl;
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