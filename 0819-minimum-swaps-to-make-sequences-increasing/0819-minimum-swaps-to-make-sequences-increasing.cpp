class Solution {
public:
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int swapped=1;swapped>=0;swapped--){

                int ans=INT_MAX;
                int prev1 = (ind == 0) ? -1 : nums1[ind - 1]; 
                int prev2 = (ind == 0) ? -1 : nums2[ind - 1];

                if(swapped)swap(prev1,prev2);

                //noswap
                if(nums1[ind]>prev1 && nums2[ind] > prev2)
                ans=next[0];

                //swap
                if(nums1[ind]>prev2 && nums2[ind] > prev1)
                ans=min(ans,1+next[1]);

                curr[swapped]=ans;
            }
            next=curr;
        }
        return next[0];
    }
};