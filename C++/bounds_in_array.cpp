/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return {-1, -1};

    int n = nums.size();

    int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (i == n || nums[i] > target)
        return {-1, -1};
    int j = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return {i, j - 1};
}

int main(){
    vector<int> nums{5,7,7,8,8,10};
    vector<int> result = searchRange( nums, 8);
    for(auto i: result){
        cout<<i<<", ";
    }

    return 0;
}