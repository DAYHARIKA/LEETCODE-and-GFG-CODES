class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){

        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int ans=0;
        if(a[i] == b[j]){
            return solve(a,b,i+1,j+1,dp);
        }else{
            int ins=1+solve(a,b,i,j+1,dp);
            int del=1+solve(a,b,i+1,j,dp);
            int rep=1+solve(a,b,i+1,j+1,dp);
            ans=min(ins,min(del,rep));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(word1,word2,0,0,dp);
    }
};