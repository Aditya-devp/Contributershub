public class BuyAndSellThree {
    public int maxProfit(int prices[]){
  dp = new int[prices.length][2][2];
  for(int i = 0;i<dp.length;i++){
      for(int j = 0;j<dp[0].length;j++){
          for(int k = 0;k<dp[0][0].length;k++){
              dp[i][j][k] = -1;
          }
      }
  }
  return maxProfit1(prices,0,0,0);
}
int dp[][][];

public int maxProfit1(int prices[], int buy, int transaction, int i){
  if(i == prices.length){
      return 0;
  }
  if(transaction == 2){
      return 0;
  }

  if(dp[i][buy][transaction] != -1){
      return dp[i][buy][transaction];
  }
  int ans;
  if(buy == 0){
      int ans1 = maxProfit1(prices,0,transaction,i+1);
      int ans2 = maxProfit1(prices,1,transaction,i+1) - prices[i];
      ans =  Math.max(ans2,ans1);
  }else{
      int ans1 = maxProfit1(prices,1,transaction,i+1);
      int ans2 = maxProfit1(prices,0,transaction+1,i+1) + prices[i];
      ans=  Math.max(ans2,ans1);
  }
  return dp[i][buy][transaction] = ans;
    }
  
}
