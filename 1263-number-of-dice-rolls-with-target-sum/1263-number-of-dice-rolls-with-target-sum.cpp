class Solution {
public:
    int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int dices=1;dices<=n;dices++){
            for(int targetsum=1;targetsum<=target;targetsum++){

                int ans=0;
                for(int i=1;i<=k;i++){
                    if(targetsum-i >= 0)
                    ans =(ans+ dp[dices-1][targetsum-i])%mod;
                }
                dp[dices][targetsum]=ans;
            }
        }
        return dp[n][target];
    }
};