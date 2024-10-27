class Solution {
public:
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,INT_MAX));
        dp[0][n-1]=0;
        dp[1][n-1]=0;
        dp[2][n-1]=0;
        dp[3][n-1]=0;
        for(int curpos=n-2;curpos>=0;curpos--){
            for(int curlane=1;curlane<=3;curlane++){

                if(obstacles[curpos+1] != curlane){
                    dp[curlane][curpos]=dp[curlane][curpos+1];
                }else{
                    int ans=INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(curlane != i && obstacles[curpos] != i)
                        ans=min(ans,1+dp[i][curpos+1]);
                    }
                    dp[curlane][curpos]=ans;
                }
            }
        }
        return min(dp[1][0]+1,min(dp[2][0],dp[3][0]+1));
    }
};