#include <bits/stdc++.h>
using namespace std;
bool prime(int x)
{
    int c=0;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(i*i==x)
            c++;
            else
            c+=2;
        }
    }
    if(c==2)
    return true;
    else 
    return false;
}
void solve() {
    int n;
    cin>>n;
    if(n%2==0&&!prime(n))
    cout<<"YES\n";
    else
    cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
        solve();
    

    return 0;
}