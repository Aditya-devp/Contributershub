" Problem Statement -- Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
  Sample Testcases -- v=[3,2,3] o/p-> 3      v=[1,2] o/p-> 1,2
"

#include<bits/stdc++.h> 
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int>mp;
        for(int x : nums) {
            mp[x]++;
        }
        for(auto it : mp) {
            if(it.second > nums.size()/3)
                ans.push_back(it.first);
        }
        return ans;
    }
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    cout<<"\nEnter elements in increasing order!";
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cout<<"\nEnter element "<<i+1<<" ";
        cin>>v[i];
    }
    
    //vector to store resultant elements
    vector<int> ans=majorityElement(v);
    
    cout<<"Majority elements are: ";
    for(int x : ans) 
    	cout<<x<<endl;

    return 0;
}
