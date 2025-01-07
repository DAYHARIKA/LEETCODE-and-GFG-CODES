class Solution {
public:
    bool check(vector<int>& nums) {

        int sorted=true;
        int x;    
        for(int i=1;i<nums.size();i++){

              if(nums[i] < nums[i-1]){
                    sorted=false;
                    x=nums.size()-i;
                    break;
              }
        }
        if(sorted==true)return true;
        vector<int> nums1(nums.size());
        for(int i=0;i<nums.size();i++){
            nums1[(i+x)%nums.size()]=nums[i];
        }
        sorted=true;
        for(int i=1;i<nums1.size();i++){

              if(nums1[i] < nums1[i-1]){
                    sorted=false;
                    break;
              }
        }
        return sorted;
    }
};