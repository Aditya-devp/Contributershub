#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    std::string getPermutation(int n, int k) {
        int f = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            f *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--;
        string ans = "";
        while (true) {
            ans += std::to_string(nums[k / f]);
            nums.erase(nums.begin() + k / f);
            if (nums.size() == 0) {
                break;
            }
            k = k % f;
            f = f / nums.size();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4; // n is the number of elements in the permutation
    int k = 9; // k is the k-th permutation to find

    string result = solution.getPermutation(n, k);
    cout << "The k-th permutation is: " << result << std::endl;

    return 0;
}


// Link to this question in leetcode: https://leetcode.com/problems/permutation-sequence/