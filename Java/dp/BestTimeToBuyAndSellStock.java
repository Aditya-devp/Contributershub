public class BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        int profit =0;
        for(int i =1 ; i<prices.length;i++){
             if(prices[i]>prices[i-1]){
                profit += prices[i] - prices[i-1];
             }
        }
        return profit;
    }
    // Recursion(TLE occur)
    public static int maxProfitRec(int[] prices , int i , int buy){
        if(i>= prices.length){return 0;}
        int profit =0;
        if(buy==1){
            int take = -prices[i] + maxProfitRec(prices , i+1 , 0); 
            int notTake =maxProfitRec(prices , i+1 , 1);
            profit = Math.max(take , notTake);
        }else{
            int sell = prices[i] + maxProfitRec(prices , i+1 , 1);
            int notSell = maxProfitRec(prices , i+1 , 0);
            profit = Math.max(sell , notSell);
        }
        return profit;
    }
    // memo
    public static int maxProfitMemo(int[] prices){
        int dp[][] = new int[prices.length][2];
        for(int i =0;i<prices.length;i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        return helper(prices,0,1,dp);
    }
    public static int helper(int[]prices , int i , int Buy , int dp[][]){
        if(i >= prices.length) return 0;
        
        if(dp[i][Buy] != -1) return dp[i][Buy];
        if(Buy == 1){
            int take = -prices[i] + helper(prices , i+1 , 0 , dp); 
            int notTake = helper(prices , i+1 , 1 , dp); 
            
            dp[i][Buy] = Math.max(take , notTake); 
        }else{
            int sell = prices[i] + helper(prices , i+1 , 1 , dp);
            int notSell = helper(prices , i+1 , 0 , dp);
            dp[i][Buy] = Math.max(sell , notSell);
        }
        
        return dp[i][Buy];
    }
   // peak valley approach
   public static int maxProfitPeakValley(int prices[]){
    int peak = prices[0];
    int valley = prices[0];
    int maxProfit = 0;
    int i = 0;
    while(i<prices.length-1){
        while(i < prices.length-1 && prices[i] >= prices[i+1])
            i++;
            valley = prices[i];
        while(i < prices.length-1 && prices[i] <= prices[i+1])
            i++;
            peak = prices[i];
        maxProfit += peak-valley;
    }
    return maxProfit;
   }
}
