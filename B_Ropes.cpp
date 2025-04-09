#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const ld eps=1e-6;
bool checker(int n,int k,ld mid,vector<int> &a)
{
    int count=0;
    for(int i=0;i<n;i++)
    count+=a[i]/mid;
    return count>=k;
}
int32_t main()
{
    cout <<fixed <<setprecision(6) <<endl;
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    ld low=0,high=*max_element(a.begin(),a.end());
    int count=0;
    while(high-low>=eps&&count<=100)
    {
        ld mid=low+(high-low)/2;
        if(checker(n,k,mid,a))
        low=mid;
        else
        high=mid;
        count++;
    }
    cout<<((low+high)/2)<<endl;
    return 0;
}