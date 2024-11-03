class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }
        if(totalsum%2 == 1)return false;
        
        vector<vector<bool>> dp(n+1,vector<bool>((totalsum/2)+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int target=1;target<=(totalsum/2);target++){
                bool inclu=false;

                if(target-nums[ind]>=0)
                inclu=dp[ind+1][target-nums[ind]];

                bool exclu=dp[ind+1][target-0];

               dp[ind][target]=(inclu || exclu);
            }
        }
        return dp[0][totalsum/2];
    }
};