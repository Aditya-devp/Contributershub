// LeetCode Problem Link :- https://leetcode.com/problems/132-pattern/
// Author :- Anup Jeejo

class Solution {
public:

    bool find132pattern(vector<int>& nums){
        int n=nums.size();
        int maxThirdElement=INT_MIN;
        stack<int> st;

        if(n<3) return false;

        for(int i=n-1; i>=0; i--)
        {
            int currNo = nums[i];
            if(currNo<maxThirdElement) return true;
            while(!st.empty() && st.top()<currNo)
            {
                maxThirdElement=st.top();
                st.pop();
            }
            st.push(currNo);
        }

        return false;
    }
};