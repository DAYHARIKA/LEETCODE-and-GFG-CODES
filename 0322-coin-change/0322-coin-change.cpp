class Solution {
public:
    int mincoins(vector<int>& coins, int amount,vector<int>& dp) {
        
        dp[0]=0;
        for(int i=1;i<=amount;i++){
           for(int j=0;j<coins.size();j++){
               
               if(i-coins[j]>= 0 && dp[i-coins[j]] != INT_MAX){
                  dp[i]=min(dp[i],dp[i-coins[j]]+1);
               }

           }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,INT_MAX);
        int ans=mincoins(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};