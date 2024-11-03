class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }
        if(totalsum%2 == 1)return false;
        
        vector<bool> curr((totalsum/2)+1,false);
        vector<bool> prev((totalsum/2)+1,false);
        
        prev[0]=true;
        curr[0]=true;
        for(int ind=n-1;ind>=0;ind--){
            for(int target=1;target<=(totalsum/2);target++){
                bool inclu=false;

                if(target-nums[ind]>=0)
                inclu=prev[target-nums[ind]];

                bool exclu=prev[target-0];

               curr[target]=(inclu || exclu);
            }
            prev=curr;
        }
        return prev[totalsum/2];
    }
};