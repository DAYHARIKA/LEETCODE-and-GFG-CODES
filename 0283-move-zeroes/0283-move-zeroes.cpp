class Solution {
public:
    void bruteforce(vector<int>& nums){
         int n=nums.size();
         vector<int> ans(n,0);
         int k=0;
         for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                ans[k]=nums[i];
                k++;
            }
         }
         for(int i=0;i<n;i++){
            nums[i]=ans[i];
         }
    }
    void moveZeroes(vector<int>& nums) {
         int i=0;
         for(int j=0;j<nums.size();j++){

            if(nums[j] != 0){
                swap(nums[j],nums[i]);
                i++;
            }
         }
    }
};