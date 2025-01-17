class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0;
        int j=0;
        int n=nums.size();
        int maxi=INT_MIN;
        while(j<n){

            while(j<n && nums[j] == 0){
                j++;
                i=j;
            }
            if(j>=n && maxi==INT_MIN)return 0;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};