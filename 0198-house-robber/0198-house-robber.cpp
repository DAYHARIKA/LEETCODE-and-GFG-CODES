class Solution {
public:
    int solve(vector<int>& nums){
        
        int n=nums.size();
        int prev1=nums[n-1];
        int prev2=0;
        for(int i=n-2;i>=0;i--){

            int inclu=nums[i]+prev2;
            int exclu=prev1;
            
            prev1=max(inclu,exclu);
            prev2=exclu;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=solve(nums);
        return ans;
    }
};