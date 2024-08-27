//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int node,int V, vector<int> adj[],int visited[]){
        queue<int> q;
        q.push(node);
        visited[node]=1;
        
        vector<int> parent(V,-1);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp]){
                if(visited[it]==1 && parent[temp] != it)
                return true;
                else if(visited[it] == 0){
                    q.push(it);
                    visited[it]=1;
                    parent[it]=temp;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        for(int i=0;i<V;i++){
        
           if(!visited[i]){
         
              bool iscycle=solve(i,V,adj,visited);
              if(iscycle)
              return true;
           }
        
        }
      return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends