class Solution {
public:
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n=obstacles.size();
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        for(int curpos=n-2;curpos>=0;curpos--){
            for(int curlane=1;curlane<=3;curlane++){

                if(obstacles[curpos+1] != curlane){
                    curr[curlane]=next[curlane];
                }else{
                    int ans=INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(curlane != i && obstacles[curpos] != i)
                        ans=min(ans,1+next[i]);
                    }
                    curr[curlane]=ans;
                }
            }
            next=curr;
        }
        return min(next[1]+1,min(next[2],next[3]+1));
    }
};