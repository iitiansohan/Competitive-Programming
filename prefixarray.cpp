#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int l,r;
    cin>>l>>r;
    vector<int> prefixsum(n);
    prefixsum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefixsum[i]=prefixsum[i-1]+arr[i];
    }
    if(l!=0)
    cout<<prefixsum[r]-prefixsum[l-1]<<endl;
    else
    cout<<prefixsum[r]<<endl;
    
    

    return 0;
}