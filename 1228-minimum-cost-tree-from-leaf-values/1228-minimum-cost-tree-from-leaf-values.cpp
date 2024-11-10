class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int> mp;

        for(int i=0;i<n;i++){
            mp[{i,i}]=arr[i];
            for(int j=i+1;j<n;j++){
                mp[{i,j}]=max(arr[j],mp[{i,j-1}]);
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int s=n-2;s>=0;s--){
            for(int e=s;e<n;e++){

                if(s==e)continue;
                else{
                   int mini=INT_MAX;
                    for(int k=s;k<e;k++){
                      mini=min(mini,mp[{s,k}]*mp[{k+1,e}]+dp[s][k]+dp[k+1][e]);
                    }
                    dp[s][e]=mini; 
                }

            }
        }
        return dp[0][n-1];
    }
};