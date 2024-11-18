class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp){

        if(i < 0 && j < 0)return true;
        if(i >= 0 && j < 0)return false;
        if(i < 0 && j >= 0){
           for(int k=0;k<=j;k++){
              if(p[k] != '*')return false;
           }
           return true;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        }else if(p[j] == '*'){
            return dp[i][j]=(solve(s,p,i,j-1,dp) || solve(s,p,i-1,j,dp));
        }else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
         int n1=s.length();
         int n2=p.length();
         vector<vector<int>> dp(n1,vector<int>(n2,-1));
         return solve(s,p,n1-1,n2-1,dp);
    }
};