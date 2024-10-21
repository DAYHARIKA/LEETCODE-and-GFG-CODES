class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int ind,vector<int>& dp){

        if(ind >= days.size()){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int op1=costs[0]+solve(days,costs,ind+1,dp);
        int i;
        for(i=ind;i<days.size() && days[i]<days[ind]+7;i++);
        int op2=costs[1]+solve(days,costs,i,dp);

        for(i=ind;i<days.size() && days[i]<days[ind]+30;i++);
        int op3=costs[2]+solve(days,costs,i,dp);

        return dp[ind]=min(op1,min(op2,op3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
          
         int n=days.size();
         vector<int> dp(n+1,-1);
         int ans=solve(days,costs,0,dp);
         return ans;
    }
};