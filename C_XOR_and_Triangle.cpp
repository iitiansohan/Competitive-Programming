#include <bits/stdc++.h>
using namespace std;
bool checker(int a,int b,int c)
{
    int mx=max(a,max(b,c));
    return mx<a+b+c-mx;
}
void solve() {
    int x;
    cin>>x;
    int numBits = (x == 0) ? 1 : (int)log2(x) + 1; 
    int ub=pow(2,numBits)-1;
    bool flag=false;
    for(int i=x;i<=ub;i++)
    {
        if(checker(x,i,x^i))
        {
            cout<<(x^i)<<endl;
            flag=true;
            break;
        }
    }
    if(!flag)
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}