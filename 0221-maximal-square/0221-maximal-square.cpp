class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {

        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

       for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){

          int adj=dp[i][j+1];
          int dia=dp[i+1][j+1];
          int bot=dp[i+1][j];

           if(matrix[i][j] == '1'){
            dp[i][j]=1+min(adj,min(dia,bot));
            maxi=max(maxi,dp[i][j]);
           }else{
             dp[i][j]=0;
           }
        }
       }
        return maxi*maxi;
    }
};