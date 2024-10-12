class Solution {
public:
    int solve(vector<int>& nums){
          
        int n = nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){

            int inclu=nums[i]+prev2;
            int exclu=prev1;

            int ans=max(inclu,exclu);

            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
         if(n ==  1){
            return nums[0];
         }
         vector<int> first;
         vector<int> second;
         for(int i=0;i<n;i++){
            if(i != 0){
                first.push_back(nums[i]);
            }
            if(i != n-1){
                second.push_back(nums[i]);
            }
         }
         return max(solve(first),solve(second));
    }
};