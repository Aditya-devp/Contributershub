// C++ program to find all duplicate items in the shopping cart
#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }

    for (int i = 0; i < n; i++) 
    {
        if ((arr[i] / n) >= 2)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    int arr[] = { 10,2,6,2,10,2,2,2,9,7,7,8 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "The repeating elements are: \n";
    vector<int> ans = duplicates(arr, arr_size);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
