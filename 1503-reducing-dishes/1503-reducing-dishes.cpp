class Solution {
public:
    int solve(vector<int>& satisfaction,int n,int index,int time,vector<vector<int>>& dp){

        if(index == n){
            return 0;
        }
        if(dp[index][time] != -1)return dp[index][time];
        int include=(time+1)*(satisfaction[index])+solve(satisfaction,n,index+1,time+1,dp);
        int exclude=solve(satisfaction,n,index+1,time,dp);
        return dp[index][time]=max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(satisfaction,n,0,0,dp);
    }
};