class Solution {
public:
    /*int solve(vector<int>& satisfaction,int n,int index,int time,vector<vector<int>>& dp){

        if(index == n){
            return 0;
        }
        if(dp[index][time] != -1)return dp[index][time];
        int include=(time+1)*(satisfaction[index])+solve(satisfaction,n,index+1,time+1,dp);
        int exclude=solve(satisfaction,n,index+1,time,dp);
        return dp[index][time]=max(include,exclude);
    }*/
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){

                int include=((j+1)*(satisfaction[i]))+dp[i+1][j+1];
                int exclude=dp[i+1][j];
                dp[i][j]=max(include,exclude); 

            }
        }
        return dp[0][0];
    }
};