class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        
        sort(pizzas.begin(),pizzas.end());
        long long maxweight=0;
        int n=pizzas.size()/4;
        int index=pizzas.size()-1;
        //odd days
        for(int i=1;i<=n;i=i+2){
            maxweight += pizzas[index];
            index--;
        }
        //even days
        index--;
        for(int i=2;i<=n;i=i+2){
            maxweight += pizzas[index];
            index=index-2;
        }
        return maxweight;
    }
    
};