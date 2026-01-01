class Solution {
public:
    int find(int i, vector<int> &parent) {
        if (parent[i] == i){
            return i;
        }
        return find(parent[i],parent);
    }
    void union_xy(int x, int y, vector<int> &parent){
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent != y_parent){
            parent[x_parent]=y_parent; // or  parent[x_parent]=y_parent; 
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        // Initialize each node as its own parent
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (find(u,parent) == find(v,parent)) {
                return edge;  // already connected - extra edge detected
            }
            
            union_xy(u, v,parent); //else union sets
        }
        
        return {};   
    }
};