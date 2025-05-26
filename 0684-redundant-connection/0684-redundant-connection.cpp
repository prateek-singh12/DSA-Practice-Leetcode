class Solution {
public:

    bool dfs(unordered_map<int , vector<int>> &adj, int u, int v, vector<bool> &visited){
        visited[u]=1;
        if(u==v){
            return true;
        }
        for(auto &it: adj[u]){
            if(visited[it]){
                continue;
            }
            if(dfs(adj,it,v,visited)){
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //CONNECTED GRAPH : nodes-n, edges-n-1
        //due to redundant connection here, 
        //number of nodes=n
        //number of edges=n 
        int n=edges.size();   
        
        unordered_map<int , vector<int>> adj; //graph banana h so map
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false); 
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(adj,u,v,visited)){
                return edges[i];
            }
            adj[u].push_back(v); //otherwise draw graph
            adj[v].push_back(u);
        }
        return {};             
    }
};