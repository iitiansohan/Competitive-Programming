#include <bits/stdc++.h>
using namespace std;
bool checker(int n,vector<int> &a)
{
    int co=0,ce=0;
    for(int i=0;i<=n;i++)
    {
        if(a[i]%2==0)
        ce++;
        else
        co++;
    }
    return co==ce;
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> temp;
    int ans=0;
    for(int i=1;i<n;i+=2)
    {
        if(i==n-1)
        break;
        if(checker(i,a))
        {
            temp.push_back(abs(a[i+1]-a[i]));
        }
    }
    sort(temp.begin(),temp.end());
    int sum=0;
    for(auto x:temp)
    {
        sum+=x;
        if(sum>k)
        break;
        
        ans++;
        // cout<<x<<" ";
    }
    cout << ans << endl;
    return 0;
}