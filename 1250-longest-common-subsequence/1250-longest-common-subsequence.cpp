class Solution {
public:
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){

        if(i>=text1.length() || j>=text2.length()){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int ans=0;
        if(text1[i] == text2[j]){
            ans=1+solve(text1,text2,i+1,j+1,dp);
        }else{
            int left=solve(text1,text2,i,j+1,dp);
            int right=solve(text1,text2,i+1,j,dp);
            ans=max(left,right);
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(text1,text2,0,0,dp);
    }
};