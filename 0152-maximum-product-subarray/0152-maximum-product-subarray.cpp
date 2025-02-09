class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int pre=0;
        int suf=0;
        int max_pro=INT_MIN;
        for(int i=0;i<n;i++){

            if(pre == 0)pre=1;
            if(suf == 0)suf=1;

            pre *= nums[i];
            suf *= nums[n-1-i];

            max_pro=max(max_pro,max(pre,suf));
        }
        return max_pro;
    }
};