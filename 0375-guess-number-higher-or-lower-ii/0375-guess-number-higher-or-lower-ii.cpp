class Solution {
public:
    
    int getMoneyAmount(int n) {
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int s=n;s>=1;s--){
            for(int e=s;e<=n;e++){

                if(s>=e)continue;
                else{
                    int mini=INT_MAX;
                    for(int i=s;i<=e;i++){
                        mini=min(mini,i+max(dp[s][i-1],dp[i+1][e]));
                    }
                    dp[s][e]=mini;
                }
            }
        }
        
        return dp[1][n];
    }
};