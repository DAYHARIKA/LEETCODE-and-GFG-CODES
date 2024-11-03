class Solution {
public:
    bool solve(vector<int>& nums,int n,int ind,int target,vector<vector<int>>& dp){

        if(ind >= n)return false;
        if(target < 0)return false;
        if(target == 0)return  true;
        if(dp[ind][target] != -1)return dp[ind][target];
        bool inclu=solve(nums,n,ind+1,target-nums[ind],dp);
        bool exclu=solve(nums,n,ind+1,target-0,dp);

        return dp[ind][target]=(inclu || exclu);
    }
    bool canPartition(vector<int>& nums) {
        
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum += nums[i];
        }
        if(totalsum%2 == 1)return false;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>((totalsum/2)+1,-1));
        return solve(nums,nums.size(),0,totalsum/2,dp);
    }
};