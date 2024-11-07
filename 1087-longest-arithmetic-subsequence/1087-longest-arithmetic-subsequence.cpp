class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=2)return n;
        unordered_map<int,int> mp[n+1];
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){

                int diff=nums[i]-nums[j];
                int cnt=1;

                if(mp[j].count(diff))
                cnt=mp[j][diff];

                mp[i][diff]=1+cnt;

                ans=max(ans,mp[i][diff]);
            }
        }
        return ans;
    }
};