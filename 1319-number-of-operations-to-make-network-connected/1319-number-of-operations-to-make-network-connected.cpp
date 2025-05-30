class Solution {
public:
    int find(int x, vector<int>& parent){
        if(x==parent[x]){
            return x;
        }
        return find(parent[x], parent);
    }
    void union_xy(int x, int y, vector<int> &parent){
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent != y_parent){
            parent[x_parent]=y_parent;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //for connected graph of n vertex , n-1 edges are needed
        int edgecount=connections.size();
        if(edgecount < n-1){return -1;}

        int connecteddevices=1;
        int extraedge=0;
        vector<int> parent(n);
        // Initialize each node as its own parent
        for (int i = 0; i < n; i++) parent[i] = i;

        for(auto edge: connections){
            int u= edge[0];
            int v=edge[1];
            if(find(u,parent)==find(v,parent)){
                extraedge++;
            }
            else {union_xy(u,v,parent);
                  connecteddevices++;}
        }
        int notconnecteddevices=n-connecteddevices;
        if(extraedge < notconnecteddevices){return -1;}
        else{return notconnecteddevices;}
    }
};