class Solution {
public:
    // void bruteforce(vector<int>& nums, int k ,int n){

    //     k=k%n; 
    //     vector<int> temp(k);
    //     for(int i=0;i<k;i++){
    //         temp[i]=nums[n-k+i];
    //     }
    //     for(int i=n-1;i>=k;i--){
    //         nums[i]=nums[i-k];
    //     }
    //     for(int i=0;i<k;i++){
    //         nums[i]=temp[i];
    //     }

    // }
    void reverse(vector<int> &nums,int i,int j){

        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void optimized(vector<int>& nums, int k ,int n){
         k=k%n;
         reverse(nums,0,n-k-1);
         reverse(nums,n-k,n-1);
         reverse(nums,0,n-1);

    }
    void rotate(vector<int>& nums, int k) {
         int n=nums.size();
         //bruteforce(nums,k,n);
         optimized(nums,k,n);
    }
};