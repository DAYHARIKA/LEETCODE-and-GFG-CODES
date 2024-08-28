//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(int node,int V, vector<int> adj[],int visit[],int func[]){
        
         visit[node]=1;
         func[node]=1;
         for(auto it:adj[node]){
             if(visit[it] == 0){
                 bool cyc=solve(it,V,adj,visit,func);
                 if(cyc)
                 return true;
             }else if(func[it] == 1){
                 return true;
             }
         }
         func[node]=0;
         return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visit[V]={0};
        int func[V]={0};
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                bool cyc=solve(i,V,adj,visit,func);
                if(cyc)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends