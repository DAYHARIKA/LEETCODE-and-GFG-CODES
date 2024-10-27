class Solution {
public:
    int solve(vector<int>& obstacles,int n,int curpos,int curlane,vector<vector<int>>& dp){

       if(curpos == n-1)return 0;
       if(dp[curlane][curpos] != -1)return dp[curlane][curpos];
       if(obstacles[curpos+1] != curlane){
          return solve(obstacles,n,curpos+1,curlane,dp);
       }else{
          int ans=INT_MAX;
          for(int i=1;i<=3;i++){
            if(curlane != i && obstacles[curpos] != i)
            ans=min(ans,1+solve(obstacles,n,curpos,i,dp));
          }
          return dp[curlane][curpos]=ans;
       }

    }
    int minSideJumps(vector<int>& obstacles) {
        
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solve(obstacles,n,0,2,dp);
    }
};