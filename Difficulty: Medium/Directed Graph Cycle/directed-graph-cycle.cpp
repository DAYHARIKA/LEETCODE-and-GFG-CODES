//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //create a indegree array
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    //insert nodes which have zero indegree into queue
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    //bfs traversal
	    int ans=0;
	    while(!q.empty()){
	        int temp=q.front();
	        ans++;
	        q.pop();
	        for(auto it:adj[temp]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    if(ans==V){
	        return false;
	    }else{
	        return true;
	    }
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