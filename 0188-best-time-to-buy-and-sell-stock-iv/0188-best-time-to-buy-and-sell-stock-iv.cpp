class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> curr(2,vector<int>(k+1,0));
         vector<vector<int>> prev(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                for(int limit=1;limit<k+1;limit++){
                    int profit=0;
                    int skip=0;
                    if(buy){
                    profit += (-prices[index])+prev[0][limit];
                    skip += 0+prev[1][limit];
                    }else{
                    profit += (prices[index])+prev[1][limit-1];
                    skip += 0+prev[0][limit]; 
                    }
                    curr[buy][limit]=max(profit,skip);
                }
                prev=curr;
            }
        }
        return prev[1][k];
    }
};