" Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
  Contributed by: Anuj Singh Kushwaha (@whyanujjwhy)
"
  
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            int moreNeeded=target-nums[i];
            if(mp.find(moreNeeded) != mp.end()) {
                return {mp[moreNeeded], i};
            }
            mp[nums[i]]=i;
        }
        return {-1, -1};
    }
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cout<<"\nEnter element "<<i+1<<" ";
        cin>>v[i];
    }
    int target;
    cout<<"Enter target value to find in pair: ";
    cin>>target;

    vector<int> ans;
    ans=twoSum(v, target);
    cout<<"Pair resultig in target value: "<<ans[0]<<" "<<ans[1];

    return 0;
}
