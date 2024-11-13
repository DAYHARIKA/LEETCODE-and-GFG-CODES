class Solution {
public:
    int solve(vector<int>& prices,int n,int index,int buy,vector<vector<int>> &dp){

        if(index >= n)return 0;
        int profit=0;
        int skip=0;
        if(dp[index][buy] != -1)return dp[index][buy];
        //buying----
        if(buy){
           profit += (-prices[index])+solve(prices,n,index+1,0,dp);
           skip += 0+solve(prices,n,index+1,1,dp);
        }else{
           profit += (prices[index])+solve(prices,n,index+1,1,dp);
           skip += 0+solve(prices,n,index+1,0,dp); 
        }
        return dp[index][buy]=max(profit,skip);
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans=solve(prices,n,0,1,dp);
        return ans;
    }
};