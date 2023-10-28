#include <bits/stdc++.h>

using namespace std;

/************** un-optimized solution **************/
// Time Complexity : O(N)
// Space Complexity : O(N)
int helper(int i, int n, vector<int> &dp){
  if(i > n) return 0;
  
  if(i == n) return 1;
  
  if(dp[i] != -1) return dp[i];
  
  return dp[i] = helper(i+1,n,dp) + helper(i+2,n,dp);
}

int climbStairsUnoptimal(int n) {
  vector<int> dp(n,-1);
  return helper(0,n,dp);
}

/************** Optimal solution **************/
// Time Complexity : O(N)
// Space Complexity : O(1)
int climbStairsOptimal(int n) {
  if(n<2) return 1;
  
  int a=1,b=1,c=0;
  
  for(int i=2;i<=n;i++){
      c=a+b;
      a=b;
      b=c;
  }
  
  return c;
}

//driver code
int main() 
{
  int n;
  cin>>n;
  cout<<"result of un-optimized solution : "<<climbStairsUnoptimal(n)<<endl;
  cout<<"result of optimized solution : "<<climbStairsOptimal(n)<<endl;
  return 0;
}