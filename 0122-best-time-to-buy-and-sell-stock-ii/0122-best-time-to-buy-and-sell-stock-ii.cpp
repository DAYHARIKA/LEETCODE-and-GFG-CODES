class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int> curr(2,0);
        vector<int> prev(2,0);
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;
                int skip=0;
                if(buy){
                   profit += (-prices[index])+prev[0];
                   skip += 0+prev[1];
                }else{
                   profit += (prices[index])+prev[1];
                   skip += 0+prev[0]; 
                }
                curr[buy]=max(profit,skip);
            }
            prev=curr;
        }
        return prev[1];
    }
};