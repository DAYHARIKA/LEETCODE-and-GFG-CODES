class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n=arr.size();
        if(n<=2)return n;
        unordered_map<int,int> mp;
        int ans=0;
            for(int j=0;j<n;j++){

                int temp=arr[j]-difference;
                int cnt=0;

                if(mp.count(temp))
                cnt=mp[temp];

                mp[arr[j]]=cnt+1;

                ans=max(ans,mp[arr[j]]);
            }
        
        return ans;
    }
    
};