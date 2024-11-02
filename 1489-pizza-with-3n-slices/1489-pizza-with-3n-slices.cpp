class Solution {
public:
    int solve(int index,int endindex,vector<int>& slices,int n,vector<vector<int>>& dp){

        if(n==0 || index > endindex)return 0;
         
        if(dp[index][n] != -1)return dp[index][n];
        int include=slices[index]+solve(index+2,endindex,slices,n-1,dp);
        int exclude=0+solve(index+1,endindex,slices,n,dp);

        return dp[index][n]=max(include,exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        
        int n=slices.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        int case1=solve(0,n-2,slices,n/3,dp1);
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        int case2=solve(1,n-1,slices,n/3,dp2);

        return max(case1,case2);
    }
};