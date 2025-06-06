class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj , int src, vector<bool> &visited){
        visited[src]=true;
        //visit neighbours
        for(int v: adj[src]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int, vector<int>> adj; //adjacency list

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count; 

    }
};