class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
             int flag=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    flag=0;
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if(flag == 0)break;
        }

        return ans;
    }
};