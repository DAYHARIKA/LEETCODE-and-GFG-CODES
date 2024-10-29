class Solution {
public:
    /*int solve(vector<int>& nums,int n,int curr,int prev,vector<vector<int>>& dp){

        if(curr == n)return 0;
        if(dp[curr][prev+1] != -1)return dp[curr][prev+1];
        int include=0;
        if(prev==-1 || nums[curr] > nums[prev])
        include=1+solve(nums,n,curr+1,curr,dp);

        int exclude=0+solve(nums,n,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }*/
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int> cur(n+1,0);
        vector<int> next(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=-1;prev<n;prev++){

                int include=0;
                if(prev==-1 || nums[curr] > nums[prev])
                include=1+next[curr+1];

                int exclude=0+next[prev+1];
                cur[prev+1]=max(include,exclude); 

            }
            next=cur;
        }
        return next[0];
    }
};