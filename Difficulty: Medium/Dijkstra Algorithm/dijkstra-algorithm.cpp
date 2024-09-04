//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //IT IS THE VECTOR FOR STORING DISTANCE FROM SRC TO ALL NODES
        vector<int> dis(V,INT_MAX);
        dis[S]=0;
        
        //set storing node,distance
        set<pair<int,int>> s;
        
        s.insert({S,0});
        
        while(!s.empty()){
            
            auto temp=*(s.begin());
            int n=temp.first;
            int d=temp.second;
            s.erase(temp);
            
            for(auto it:adj[n]){
                
                int first=it[0];
                int second=it[1];
                
                if(d+second < dis[first]){
                    
                    if(dis[first] != INT_MAX){
                    
                      s.erase({first,dis[first]});
                      dis[first]=d+second;
                      s.insert({first,d+second});
                    
                    }else{
                        
                        dis[first]=d+second;
                        s.insert({first,d+second});
                        
                    }
                    
                }
                
            }
        }
        
        return dis;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends