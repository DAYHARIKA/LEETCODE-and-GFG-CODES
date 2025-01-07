class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long maxi=LONG_MIN;
        long second_maxi=LONG_MIN;
        long third_maxi=LONG_MIN;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] > maxi){
                third_maxi=second_maxi;
                second_maxi=maxi;
                maxi=nums[i];
            }else if(nums[i] > second_maxi && nums[i] < maxi){
                third_maxi=second_maxi;
                second_maxi=nums[i];
            }else if(nums[i] > third_maxi && nums[i] < second_maxi){
                third_maxi=nums[i];
            }
            
        }
        if(third_maxi == LONG_MIN)return maxi;
        else return third_maxi;
    }
};