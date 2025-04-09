#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin>>str;
    string s1,s2;
    int n=str.length();
    bool flag=false;
    int count;
    for(int t=1;t<n-1;t++)
    {
        s1="",s2="";
        count=0;
        for(int i=0;i<=t;i++)
        {
            s1=s1+str[i];
            count++;
        }
        for(int i=n-1;i>=n-t-1;i--)
        {
            s2=str[i]+s2;
        }
        if(s1.compare(s2)==0&&count>n/2&&count<n)
        {
            flag=true;
            break;
        } 
    }
    if(flag)
    {
        yes;
        cout<<s1<<endl;

    }  
    else
    no; 
    

    return 0;
}