// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    // Write C++ code here
    int H,n;
    cin>>H>>n;
    vector<int> d(n);
    int sum=0;
    int mn=INT_MAX;
    int h=H;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        sum+=d[i];
        mn=min(mn,sum);
        h+=d[i];
        if(h<=0)
        {cout<<i+1<<endl;return 0;}
    }
    if((sum>=0))
    {
        cout<<-1<<endl;
        return 0;
    }
    int whole=ceil(((double)H+(double)mn)/-sum);
    H=H+whole*sum;
    int count=whole*n;
    for(int i=0;;i++)
    {
        if(H<=0)
        break;
        H+=d[i%n];
        count++;
    }
    cout<<count<<endl;

    return 0;
}