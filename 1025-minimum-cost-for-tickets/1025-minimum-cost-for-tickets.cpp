class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int n,vector<int>& dp){    
      dp[n]=0;
      for(int k=n-1;k>=0;k--){
        int op1=costs[0]+dp[k+1];
        int i;
        for(i=k;i<days.size() && days[i]<days[k]+7;i++);
        int op2=costs[1]+dp[i];

        for(i=k;i<days.size() && days[i]<days[k]+30;i++);
        int op3=costs[2]+dp[i];

         dp[k]=min(op1,min(op2,op3));
      }
      return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
          
         int n=days.size();
         vector<int> dp(n+1,INT_MAX);
         int ans=solve(days,costs,n,dp);
         return ans;
    }
};