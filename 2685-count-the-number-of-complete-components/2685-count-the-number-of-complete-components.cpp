class Solution {
public:
    void dfs( unordered_map<int,vector<int>> &adj, vector<bool> &visited, int src, int &e, int &v){       
        v++;
        e += adj[src].size(); //containt duplicates 2*actual
        visited[src]=true;
        for(auto node: adj[src] ){
            if(!visited[node]){
                dfs(adj,visited,node,e,v);
            }
        }        

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>> adj;
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int edgecount=0;
                int vertexcount=0;
                dfs(adj,visited,i,edgecount,vertexcount);
                if((vertexcount*(vertexcount-1)) == edgecount){
                ans++;
                }
            }            
        }
        return ans;
    }
};