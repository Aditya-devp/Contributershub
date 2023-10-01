class Solution
{
  
    public:
    
    // Using memoization method or Top-down approach  
    int solveMemo(int wt[], int val[], int n, int W, vector<vector<int> >& dp)
    {
        if(n == 0){
            if(wt[n] <= W){
                return val[n];
            }
            else{
                return 0;
            }
        }
        
        if(dp[n][W] != -1)
        return dp[n][W];
        
        int include = 0;
        if(wt[n] <= W)
        include = val[n] + solveMemo(wt,val,n-1,W-wt[n],dp); val[n] ko add krna h*  
        
      int exclude = 0 + solveMemo(wt,val,n-1,W,dp);
        
        dp[n][W] = max(include,exclude);
        return dp[n][W];
    }
    
    // Using Tabulation method or bottom-up approach
    int solveWithTabul(int wt[],int val[], int n, int capacity)
    {
        vector<vector<int> >dp(n,vector<int>(capacity+1,-1));
        for(int w = 0; w<=capacity; w++)
        {
            if(wt[0] <= w){
                dp[0][w] = val[0];
            }
            else{
                dp[0][w] = 0;
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=capacity; j++){
        int include = 0;
        if(wt[i] <= j)
        include = val[i] + dp[i-1][j-wt[i]];
        
       int exclude = 0 + dp[i-1][j];
        
        dp[i][j] = max(include,exclude);
       
            }
        }
         return dp[n-1][capacity];
        }
    
    // using Space optimization technique
    int solveWithOS(int wt[],int val[], int n, int capacity)
    {
        vector<int> prev(capacity+1,0);
        vector<int> curr(capacity+1,0);
        for(int w = 0; w<=capacity; w++)
        {
            if(wt[0] <= w){
                prev[w] = val[0];
            }
            else{
                prev[w] = 0;
            }
        }
        
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<=capacity; j++)
            {
        int include = 0;
        if(wt[i] <= j)
        include = val[i] + prev[j-wt[i]];
        
       int exclude = 0 + prev[j];
        
        curr[j] = max(include,exclude);
        
      }
       prev = curr;
     
  }
  return prev[capacity];
  }
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   Here n = index of last element while we are moving right to left.
      if(n == 0){
          if(wt[n] <= W){
              return val[n];
          }
          else{
              return 0;
          }
      }
       
      int include = 0;
      if(wt[n] <= W)
      include = val[n] + knapSack(W-wt[n],wt,val,n-1);
       
      int exclude = 0 + knapSack(W,wt,val,n-1);
       
      int ans = max(include,exclude);
      return ans;
       
      vector<vector<int> >dp(n, vector<int>(W+1,-1));
      int ans = solveMemo(wt,val,n-1,W,dp);
      return ans;
       
      int ans = solveWithTabul(wt,val,n,W);
      return ans;
       
       int ans = solveWithOS(wt,val,n,W);
       return ans;
       
       
       
    }
};
