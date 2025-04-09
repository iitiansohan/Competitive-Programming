#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> copy = arr;
        sort(arr.begin(), arr.end(), greater<int>());
        if (k != 1)
        {
            int ans = 0;
            for (int i = 0; i <= k; i++)
                ans += arr[i];
            cout << ans << endl;
        }
        else
        {
            int ans;
            if (arr[1] > copy[0] and arr[1] > copy[n - 1])
                ans = max(copy[0], copy[n - 1]) + arr[0];
            else
                ans = arr[0] + arr[1];
            cout << ans << endl;
        }
    }
    return 0;
}