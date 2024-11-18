class Solution {
public:
    
    bool isMatch(string s, string p) {
         int n1=s.length();
         int n2=p.length();
         vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
         dp[0][0]=true;
         for(int j=1;j<=n2;j++){
             int flag=true;
            for(int k=1;k<=j;k++){
              if(p[k-1] != '*'){
                 flag=false;
                 break;
              }
           }
           dp[0][j]=flag;
         }
         for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j]= (dp[i][j-1] || dp[i-1][j]);
                }else{
                    dp[i][j]=  false;
                }
            }
         }
         return dp[n1][n2];
    }
};