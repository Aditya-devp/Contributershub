/*
Description of code

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order

*/
#include<bits/stdc++.h>
using namespace std;

//temporary vector to store temp array.
vector<int> temp;

void solve(vector<int> nums, set<vector<int>> &table, int idx, int n)
{
    if (idx == n)
    {
        sort(temp.begin(), temp.end());
        table.insert(temp);
    }
    else
    {
        temp.push_back(nums[idx]);
        solve(nums, table, idx + 1, n);
        temp.pop_back();
        solve(nums, table, idx + 1, n);
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    set<vector<int>> table;
    int n = nums.size();
    vector<int> temp;

    solve(nums, table, 0, n);

    for (auto i : table)
    {
        result.push_back(i);
    }

    return result;
}

int main(){
    vector<int> nums{1,2,2};

    vector<vector<int>> result = subsetsWithDup(nums);
    for(auto i: result){
        for(auto j:i){
            cout<<j<<", ";
        }
        cout<<endl;
    }

    return 0;
}