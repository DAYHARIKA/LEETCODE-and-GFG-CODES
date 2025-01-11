class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <= 2)return nums.size();
        int i=0;
        for(int j=2;j<nums.size();j++){

            if(nums[i]  != nums[j]){
                nums[i+2]=nums[j];
                i++;
            }
        }
        return i+2;
    }
};