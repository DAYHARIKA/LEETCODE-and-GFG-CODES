//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    int timer=0;
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &low, vector<int> &disc, vector<int> &ans){
        visited[node]=1;
        low[node]=disc[node]=timer++;
        
        int child=0;
        for(int nbr:adj[node]){
            if(nbr==parent) continue;
            else if(!visited[nbr]){
                dfs(nbr, node, adj, visited, low, disc, ans);
                low[node]=min(low[node], low[nbr]);
                
                if(low[nbr]>=disc[node] && parent!=-1){
                    ans.push_back(node);
                }
                child++;
            }
            else{
                low[node]=min(low[node], disc[nbr]);
            }
        }
        
        if(child>1 && parent == -1)
            ans.push_back(node);
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> low(V, -1), disc(V, -1);
        vector<bool> visited(V, 0);
        vector<int> ans;
        
        for(int i=0; i<V; i++){
            if(!visited[i])
                dfs(i, -1, adj, visited, low, disc, ans);
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        if(ans.size()==0)   ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends