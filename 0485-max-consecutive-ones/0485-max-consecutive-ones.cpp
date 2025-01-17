class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0;
        int cnt=0;
        int maxi=0;

        for(int i=0;i<nums.size();i++){

            if(nums[i] != 1)cnt=0;
            else{
                cnt++;
                maxi=max(maxi,cnt);
            }
        }

        return maxi;
    }
};