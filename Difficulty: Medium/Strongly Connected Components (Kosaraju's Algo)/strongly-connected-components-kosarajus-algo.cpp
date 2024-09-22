//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int n,int p,vector<vector<int>>& adj,stack<int>& st,vector<int>& visited){
	    
	    visited[n]=1;
	    for(auto it:adj[n]){
	       if(!visited[it]){
	           dfs(it,n,adj,st,visited);
	       }
	    }
	    st.push(n);
	}
	void dfs_new(int n,int p,vector<vector<int>>& new_adj,vector<int>& visited){
	    
	    visited[n]=1;
	    for(auto it:new_adj[n]){
	       if(!visited[it]){
	           dfs_new(it,n,new_adj,visited);
	       }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //finding finishing times---------step1
        stack<int> st;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,adj,st,visited);
            }
        }
        //reverse the edges------------step2
        vector<vector<int>> new_adj(V);
        for(int i=0;i<V;i++){
            visited[i]=0;
           for(auto it:adj[i]){
               new_adj[it].push_back(i);
           }
        }
        
        //finding no of scc's----------step3
        int cnt=0;
        while(!st.empty()){
            
             int t=st.top();
             st.pop();
             
             if(!visited[t]){
                cnt++;
                dfs_new(t,-1,new_adj,visited);
             }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends