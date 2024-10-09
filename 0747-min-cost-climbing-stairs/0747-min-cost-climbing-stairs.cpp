class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ptr1=cost[0];
        int ptr2=cost[1];

        for(int i=2;i<n;i++){
            int res=cost[i]+min(ptr1,ptr2);
            ptr1=ptr2;
            ptr2=res;
        }
        return min(ptr1,ptr2);
    }
};