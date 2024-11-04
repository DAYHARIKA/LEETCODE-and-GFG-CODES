class Solution {
public:
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int swapped=1;swapped>=0;swapped--){

                int ans=INT_MAX;
                int prev1 = (ind == 0) ? -1 : nums1[ind - 1]; 
                int prev2 = (ind == 0) ? -1 : nums2[ind - 1];

                if(swapped)swap(prev1,prev2);

                //noswap
                if(nums1[ind]>prev1 && nums2[ind] > prev2)
                ans=dp[ind+1][0];

                //swap
                if(nums1[ind]>prev2 && nums2[ind] > prev1)
                ans=min(ans,1+dp[ind+1][1]);

                dp[ind][swapped]=ans;
            }
        }
        return dp[0][0];
    }
};