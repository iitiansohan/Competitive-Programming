#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int now = n;
    long long ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = 1; j <= now; j++) sum = (sum + a[j]) ;
        if (i == 1) ans = max(ans, sum);
        else ans = max(ans, abs(sum));
        for (int i = 1; i < now; i++) a[i] = (a[i + 1] - a[i]) ;
        now--;
    }
    cout << ans << endl;     
}
int32_t main(){
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}