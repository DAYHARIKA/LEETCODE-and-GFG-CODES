class Solution {
public:
    int solve(int n,vector<int>& dp){

        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }
        if(dp[n] != -1)return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){

            int temp=solve(n-(i*i),dp);
            if(temp != INT_MAX){
                ans=min(ans,temp+1);
            }
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        
        vector<int> dp(n+1,-1);
        int output=solve(n,dp);
        if(output == INT_MAX)return -1;
        else return output;
    }
};