#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int sum_of_digits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int32_t main() 
{
    int N = 2e5;  // Define the range
    int arr[200001];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=N;i++)
    {
        arr[i]=arr[i-1]+sum_of_digits(i);
    }
    int t;
    cin>>t;
    vector<int> res (t);
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        res[i]=arr[n];
    }
    for(int i=0;i<t;i++)
    cout<<res[i]<<endl;

}