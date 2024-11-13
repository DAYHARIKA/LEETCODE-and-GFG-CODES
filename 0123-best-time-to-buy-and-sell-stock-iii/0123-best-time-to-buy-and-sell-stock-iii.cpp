class Solution {
public:
    int solve(vector<int>& prices,int n,int index,int buy,int limit,vector<vector<vector<int>>> &dp){

        if(index >= n)return 0;
        if(limit == 0)return 0;
        int profit=0;
        int skip=0;
        int maxi=INT_MIN;
        if(dp[index][buy][limit] != -1)return dp[index][buy][limit];
        //buying----
        if(buy){
           profit += (-prices[index])+solve(prices,n,index+1,0,limit,dp);
           skip += 0+solve(prices,n,index+1,1,limit,dp);
           maxi=max(profit,skip);
        }else{
           profit += (prices[index])+solve(prices,n,index+1,1,limit-1,dp);
           skip += 0+solve(prices,n,index+1,0,limit,dp); 
           maxi=max(profit,skip);
        }
        return dp[index][buy][limit]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=solve(prices,n,0,1,2,dp);
        return ans;
    }
};