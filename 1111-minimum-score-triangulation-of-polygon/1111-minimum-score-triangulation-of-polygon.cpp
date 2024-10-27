class Solution {
public:
    int solve(vector<int>& v,int i,int j,vector<vector<int>>& dp){

        if(i+1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        
        int n=values.size();
        vector<vector<int>> dp(n-1,vector<int>(n,-1));
        int ans=solve(values,0,n-1,dp);
        return ans;

    }
};