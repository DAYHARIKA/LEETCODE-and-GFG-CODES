class Solution {
public:
    int solve(int s,int e,vector<vector<int>> &dp){
        
        if(s >= e)return 0;
        if(dp[s][e] != -1)return dp[s][e];
        int mini=INT_MAX;
        for(int i=s;i<=e;i++){
            mini=min(mini,i+max(solve(s,i-1,dp),solve(i+1,e,dp)));
        }
        return dp[s][e]=mini;
    }
    int getMoneyAmount(int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=solve(1,n,dp);
        return ans;
    }
};