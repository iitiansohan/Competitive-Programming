#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " = " << x << "\n"
#define int long long
const int N=1e6;

bool isPrime[N+1];
vector<int>cnt(N+1);


void sieve(){
    for(int i=1; i<=N; i++) isPrime[i]=1;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for(int i=1; i<=N; i++){
        cnt[i]=cnt[i-1];
        if(isPrime[i]) cnt[i]++;
    }

}

void solve(){
    int n; cin>>n;
    int k=sqrtl(n);
    int ans=1;
    for(int i=k+1;i<=n;i++)
    {
        if(isPrime[i]) ans++;
    }
    cout<<ans<<endl;
    // cout<<cnt[n]-cnt[k]+1<<"\n";
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    sieve();

    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}