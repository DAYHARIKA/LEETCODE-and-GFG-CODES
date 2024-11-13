class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                for(int limit=1;limit<3;limit++){
                    int profit=0;
                    int skip=0;
                    if(buy){
                    profit += (-prices[index])+dp[index+1][0][limit];
                    skip += 0+dp[index+1][1][limit];
                    }else{
                    profit += (prices[index])+dp[index+1][1][limit-1];
                    skip += 0+dp[index+1][0][limit]; 
                    }
                    dp[index][buy][limit]=max(profit,skip);
                }
            }
        }
        return dp[0][1][2];
    }
};