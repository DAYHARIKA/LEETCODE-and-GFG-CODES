class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(int i = 0; i < cuboids.size(); i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        //sorting the array
        sort(cuboids.begin(),cuboids.end());
        //dp array(pos,prev)
        vector<int> curr(cuboids.size()+1,0);
        vector<int> forw(cuboids.size()+1,0);
        for(int pos = cuboids.size() - 1; pos >= 0; pos--){
            for(int prev = pos - 1; prev >= -1; prev--){
                int skip = forw[prev+1];
                int take = 0;
                if(prev == -1 || (cuboids[prev][0] <= cuboids[pos][0] && cuboids[prev][1] <= cuboids[pos][1] && cuboids[prev][2] <= cuboids[pos][2])){
                    take = cuboids[pos][2] + forw[pos+1];
                }
                curr[prev+1] = max(skip,take);
            }
            forw = curr;
        }
        return curr[0];
    }
};