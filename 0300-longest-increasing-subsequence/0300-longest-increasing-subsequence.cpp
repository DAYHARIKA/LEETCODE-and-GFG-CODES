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
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){

            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
};