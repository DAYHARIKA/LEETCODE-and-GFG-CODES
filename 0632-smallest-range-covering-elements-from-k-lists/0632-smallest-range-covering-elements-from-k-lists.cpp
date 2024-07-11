class Solution {
public:
    class node{
        public:
        int mini;
        int x;
        int y;
        node(int minn,int X,int Y){
              mini=minn;
              x=X;
              y=Y;
        }
    };
    class comp{
        public:
        bool operator()(node a,node b){
            return a.mini>b.mini;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<int> ans(2,0);
        priority_queue<node,vector<node>,comp> pq;
        int minele=INT_MAX;
        int maxele=INT_MIN;
        for(int i=0;i<k;i++){
            if(nums[i].size() != 0){
            pq.push({nums[i][0],i,0});
            minele=min(minele,nums[i][0]);
            maxele=max(maxele,nums[i][0]);
            }
        }
        int minlen=INT_MAX;
        while(!pq.empty()){
              node temp=pq.top();
              pq.pop();
              int row=temp.x;
              int col=temp.y;
              minele=temp.mini;
              int len=maxele-minele+1;
              if(len<minlen){
                minlen=len;
                ans[0]=minele;
                ans[1]=maxele;
              }
              col++;
              if(col==nums[row].size()){
                break;
              }
              pq.push({nums[row][col],row,col});
              maxele=max(maxele,nums[row][col]);
        }
        return ans;
    }
};