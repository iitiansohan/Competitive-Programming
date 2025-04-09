#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][2][11];
int f(int ind, int tight, int sumr, string num)
{
    if (sumr < 0)
        return 0;
    if (ind == num.size())
        return (sumr == 0);
    if (dp[ind][tight][sumr] != -1)
        return dp[ind][tight][sumr];
    int res = 0;
    int ub = tight ? (num[ind] - '0') : 9;
    for (int i = 0; i <= ub; i++)
    {
        res += f(ind + 1, tight && (i == ub), sumr - i, num);
    }
    return dp[ind][tight][sumr] = res;
}
int find(int x)
{
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return f(0, 1, 10, num);
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int lo = 19, hi = 1e18, mid, ans = -1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (find(mid) < k)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
