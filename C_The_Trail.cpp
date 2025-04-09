#include <bits/stdc++.h>
using namespace std;
#define int long long
void sohan()
{
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a[n+1][m+1], mark[n+1][m+1];
    memset(mark,0,sizeof(mark));
    int rr[n+1]{}, cl[m+1]{};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin >> a[i][j], rr[i]+=a[i][j], cl[j]+=a[i][j];
    }
    int l=1, r=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='D')
        {
            int temp=-rr[l];
            a[l][r]=temp;
            rr[l]=temp+a[l][r];
            cl[r]+=temp;
            l++;
        }
        else
        {
            int temp=-cl[r];
            a[l][r]=temp;
            cl[r]=temp+a[l][r];
            rr[l]+=temp;
            r++;
        }
    }
    a[n][m]=-cl[m];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout << a[i][j] << " ";
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        sohan();
    }

    return 0;
}