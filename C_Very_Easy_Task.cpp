#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
int32_t main()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) swap(x, y);
    int low = 0, high = n * x;
    int result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long totalCopies = (mid / x) + (mid / y);
        if (totalCopies + 1 >= n) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << result+min(x,y) << endl;

    return 0;
}