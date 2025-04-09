#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<string> str(t);
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        char n1=97,n2=97,n3=97;
        bool flag=true;
        for(int a=1;a<=26&&flag;a++)
        {
            for(int b=1;b<=26&&flag;b++)
            {
                for(int c=1;c<=26&&flag;c++)
                {
                    if((a+b+c)==n)
                    {
                        n1=a+96;
                        n2=b+96;
                        n3=c+96;
                        flag=false;
                    }
                }
            }
        }
        
        str[i]="";
        str[i]=string(1,n1)+n2+n3;

    }
    for(int i=0;i<t;i++)
    cout<<str[i]<<endl;
    

    return 0;
}