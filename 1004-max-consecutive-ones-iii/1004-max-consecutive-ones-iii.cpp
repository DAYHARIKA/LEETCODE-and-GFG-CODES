class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0,l=0,r=0;
        int count=0;
        while(r<nums.size()){
            if(nums[r]==0){
                count++;
            }
            if(count>k){
                if(nums[l]==0)
                 count--;
                 l++;
            }else{
             maxlen=max(maxlen,r-l+1);
            }
            r++;
            
        }
        return maxlen;
    }
};