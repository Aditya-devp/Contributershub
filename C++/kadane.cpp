// Kadane's Algorithm is used to solve the famous problem - Maximum Subarray Sum
// maxi=arr[0]
// sum=0
// 1>sum=sum+arr[i]
// 2>maxi=maximum of sum and maxi
// 3>if sum<0 put sum=0

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &array)
{
    int curr_sum = 0;
    int max_sum = array[0];
    for (int i = 0; i < array.size(); i++)
    {
        curr_sum += array[i];
        max_sum = max(max_sum, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
    }

    return max_sum;
}
int main()
{
    int size_array;
    cin >> size_array;
    vector<int> array;
    for (int i = 0; i < size_array; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }

    cout << maxSubArray(array);

    return 0;
}
