#include <bits/stdc++.h>
using namespace std;
// bool checker(vector<int> &a)
// {
//     bool flag=true;
//     int n=a.size();
//     for(int i=1;i<n;i++)
//     {
//         if(a[i]<=a[i-1])
//         {
//             flag=false;
//             break;
//         }
//     }
//     return flag;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;
    vector<int> e(k);
    for(int i=0;i<k;i++)
    cin>>e[i];
    cout<<k+1<<endl;
    int sum=0;
    for(int i=k-1;i>=0;i--)
    {
        int key=((k+i)-(e[i]+sum)%k)%k;
        cout<<1<<" "<<(i+1)<<" "<<(key)<<endl;;
        sum+=key;
    }
    cout<<2<<" "<<k<<" "<<k<<endl;

    

    return 0;
}