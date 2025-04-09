#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isValid(int threshold, int size, int maxOps, const string &directions, const vector<int> &values)
{
    int operations = 0, index = 0;
    while (index < size)
    {
        if (directions[index] == 'R' && values[index] > threshold)
        {
            index++;
            continue;
        }
        bool requiresOp = false;
        while (index < size && !(directions[index] == 'R' && values[index] > threshold))
        {
            if (directions[index] == 'B' && values[index] > threshold)
                requiresOp = true;
            index++;
        }
        if (requiresOp)
            operations++;
    }
    return operations <= maxOps;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int size, maxOps;
        cin >> size >> maxOps;
        string directions;
        cin >> directions;
        vector<int> values(size);
        int maxValue = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> values[i];
            maxValue = max(maxValue, values[i]);
        }

        int left = 0, right = maxValue, result = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (isValid(mid, size, maxOps, directions, values))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << result << "\n";
    }

    return 0;
}
