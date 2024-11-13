class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;
                int skip=0;
                if(buy){
                   profit += (-prices[index])+dp[index+1][0];
                   skip += 0+dp[index+1][1];
                }else{
                   profit += (prices[index])+dp[index+1][1];
                   skip += 0+dp[index+1][0]; 
                }
                dp[index][buy]=max(profit,skip);
            }
        }
        return dp[0][1];
    }
};