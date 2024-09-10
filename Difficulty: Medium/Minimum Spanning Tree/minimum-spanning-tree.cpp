//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class dis{
    public:
    vector<int> parent,size;
    dis(int v){
        parent.resize(v,0);
        size.resize(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int ultimate_parent(int node){
        if(node == parent[node]){
            return node;
        }else{
            int p=ultimate_parent(parent[node]);
            parent[node]=p;
            return p;
        }
    }
    
    void union_size(int u,int v){
        
        int ul_u=ultimate_parent(u);
        int ul_v=ultimate_parent(v);
        
        if(size[ul_u] > size[ul_v]){
            parent[ul_v]=ul_u;
            size[ul_u] += size[ul_v];
        }else{
            parent[ul_u]=ul_v;
            size[ul_v] += size[ul_u];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            
            for(auto it:adj[i]){
                int a=it[0];
                int w=it[1];
                int n=i;
                edges.push_back({w,{n,a}});
            }
        }
        
        //sort edges list
        sort(edges.begin(),edges.end());
        
        dis d(V);
        int wt=0;
        for(auto it:edges){
            
            int w=it.first;
            int n=it.second.first;
            int a=it.second.second;
            
            if(d.ultimate_parent(n) != d.ultimate_parent(a)){
                wt += w;
                d.union_size(n,a);
            }
        }
        
        return wt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends