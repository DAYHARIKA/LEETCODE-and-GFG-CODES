class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int max_fre=INT_MIN;
        long long sum = 0;
        int r=0,l=0;
        while(r < n){
             
            sum += nums[r];
            while((long long)nums[r]*(r-l+1) > sum+k){

                sum=sum-nums[l];
                l++;
            }
            max_fre=max(max_fre,r-l+1);
            r++;
        }
 
        return max_fre;
    }
};