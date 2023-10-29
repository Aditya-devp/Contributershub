// LeetCode Problem Link :- https://leetcode.com/problems/powx-n/
// Author :- Anup Jeejo

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long N = n;
        
        if(N<0) N *= -1;
        
        while(N){
            if(N%2){
                ans *= x;
                N--;
            }else{
                x *= x;
                N /= 2;
            }
        }
        
        if(n<0) ans = (double)1.0/(double)ans;
        
        return ans;
    }
};