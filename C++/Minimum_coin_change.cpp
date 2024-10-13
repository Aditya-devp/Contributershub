#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &arr, vector<int> &dp, int n, int m)
{
    // Base case: If the desired sum 'm' is 0, no coins are needed.
    if (m == 0)
        return 0;

    // If the result for this sum 'm' has already been computed, return it.
    if (dp[m] != -1)
        return dp[m];

    // Initialize 'ans' to a large value as a placeholder for the minimum.
    int ans = INT_MAX;

    // Iterate through each available coin to consider using it.
    for (int i = 0; i < n; i++)
    {
        // Check if the current coin value 'arr[i]' can be subtracted from 'm'.
        if (m - arr[i] >= 0)
        {
            // Recursively find the minimum number of coins for the reduced sum.
            int val = count(arr, dp, n, m - arr[i]);

            // If 'val' is not INT_MAX (i.e., a valid solution exists) and
            // 'val + 1' is smaller than the current 'ans', update 'ans'.
            if (val != INT_MAX && val + 1 < ans)
                ans = val + 1;
        }
    }

    // Store the result in 'dp' to avoid recomputation and return 'ans'.
    dp[m] = ans;
    return ans;
}

int main()
{
    int n, m;
    // 'n' is the number of available coins.
    // 'm' is the total sum we have to achive.
    cin >> n >> m;

    vector<int> arr;
    // Input the values of 'n' coins.
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // Initialize the memoization array 'dp' with -1.
    vector<int> dp(m + 1, -1);

    // Call the 'count' function to find the minimum number of coins needed.
    int val = count(arr, dp, n, m);

    // If a valid solution exists (i.e., 'val' is not INT_MAX), print the result.
    if (val != INT_MAX)
        cout << val;
    // If it's not possible to make the desired sum, print "-1".
    else
        cout << "-1";
}
