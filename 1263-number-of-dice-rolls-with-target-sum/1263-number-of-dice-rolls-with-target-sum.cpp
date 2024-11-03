class Solution {
public:
    int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {

        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0]=1;
        for(int dices=1;dices<=n;dices++){
            for(int targetsum=1;targetsum<=target;targetsum++){

                int ans=0;
                for(int i=1;i<=k;i++){
                    if(targetsum-i >= 0)
                    ans =(ans+ prev[targetsum-i])%mod;
                }
                curr[targetsum]=ans;
            }
            prev=curr;
        }
        return prev[target];
    }
};