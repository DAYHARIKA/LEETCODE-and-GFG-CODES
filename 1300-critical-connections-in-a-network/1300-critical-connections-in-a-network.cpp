class Solution {
public:
    void dfs(int node,int p,int i_t,vector<vector<int>>& adj,vector<int>& visited,vector<int>& intime,vector<int>& lowtime,vector<vector<int>>& bridges) {
       
        visited[node]=1;
        intime[node]=lowtime[node]=i_t;
        i_t++;
        for(auto it:adj[node]){
            if(it == p){
               continue;
            }else if(!visited[it]){
                dfs(it,node,i_t,adj,visited,intime,lowtime,bridges);
                
                lowtime[node]=min(lowtime[it],lowtime[node]);
                
                if(lowtime[it]>intime[node]){
                    bridges.push_back({node,it});
                }
            }else{
                lowtime[node]=min(lowtime[it],lowtime[node]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> intime(n);
        vector<int> visited(n,0);
        vector<int> lowtime(n);
        vector<vector<int>> bridges;
        dfs(0,-1,1,adj,visited,intime,lowtime,bridges);
        return bridges;
    }
};