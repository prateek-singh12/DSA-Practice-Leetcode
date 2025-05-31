class Solution {
public:
    int find(int node, vector<int>& parent){
        if(node==parent[node]){
            return node;
        }
        return find(parent[node],parent);

    }
    void union_xy(int x, int y, vector<int> &parent){
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent!=y_parent){
            parent[x_parent]=y_parent;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][1]==stones[j][1] || stones[i][0]==stones[j][0]){
                    union_xy(i,j,parent);
                }
            }
        }

        //count diff no of groups
        int grp=0;
        for(int i=0;i<n;i++){
            if(i==parent[i]){//means element is parent of itself i.e. not part of any other group
                grp++;
            }
        }
        return n-grp;
    }
};