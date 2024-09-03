//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node,int visited[],stack<int> &s,vector<vector<pair<int,int>>> &v){
        
        visited[node]=1;
        for(auto it:v[node]){
            if(!visited[it.first]){
                dfs(it.first,visited,s,v);
            }
        }
        s.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //create adjacency list
        vector<vector<pair<int,int>>> v(N);
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int r=edges[i][1];
            int w=edges[i][2];
            v[u].push_back({r,w});
        }
        
        //find topological sort
        int visited[N]={0};
        stack<int> s;
        dfs(0,visited,s,v);
        
        //finding shortest path
        vector<int> dis(N,-1);
        dis[0]=0;
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            if(dis[temp] !=  -1){
                for(auto it:v[temp]){
                    if(dis[temp]+it.second < dis[it.first] || dis[it.first]==-1){
                        dis[it.first]=dis[temp]+it.second;
                    }
                }
            }
        }
        
        
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends