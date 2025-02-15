class Solution {
public:
    int sumDivisors(vector<int>& nums,int div,int threshold){

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += ceil(nums[i]/(double)div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1;
        int high=maxi;
        while(low <= high){
            int mid=(low+high)/2;
            int sum=sumDivisors(nums,mid,threshold);
            if(sum <= threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};