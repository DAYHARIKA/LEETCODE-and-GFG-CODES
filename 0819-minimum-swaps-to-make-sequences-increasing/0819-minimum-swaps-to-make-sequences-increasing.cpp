class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int ind, bool swapped, vector<vector<int>> &dp){

        if(nums1.size() == ind){
            return 0;
        }

        if(dp[ind][swapped] != -1)return dp[ind][swapped];
        int ans=INT_MAX;
        int prev1 = (ind == 0) ? -1 : nums1[ind - 1]; 
        int prev2 = (ind == 0) ? -1 : nums2[ind - 1];

        if(swapped)swap(prev1,prev2);

        //noswap
        if(nums1[ind]>prev1 && nums2[ind] > prev2)
        ans=solve(nums1,nums2,ind+1,false,dp);

        //swap
        if(nums1[ind]>prev2 && nums2[ind] > prev1)
        ans=min(ans,1+solve(nums1,nums2,ind+1,true,dp));

        return dp[ind][swapped]=ans;
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        bool swapped=false;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(nums1,nums2,0,swapped,dp);
    }
};