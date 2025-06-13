class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> dist;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                dist.push_back({i, j, d}); // naming points as 0,1,2,3...
            }
        }
        // KRUSKAL- dsu
        auto comparator = [&](vector<int> v1, vector<int> v2) {
            return v1[2] < v2[2];
        };
        sort(dist.begin(), dist.end(), comparator);

        vector<int> parent(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int cost = 0;
        for (auto edge : dist) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (find(u, parent) != find(v, parent)) {
                union_xy(u, v, parent);
                cost += w;
            }
        }
        return cost;
    }
    int find(int x, vector<int>& parent) {
        if (x== parent[x]) {
            return parent[x];  
        }
        return find(parent[x], parent);
    }

    void union_xy(int x, int y, vector<int>& parent) {
        int fx = find(x, parent);
        int fy = find(y, parent);
        if (fx != fy)
            parent[fx]=fy;
    }
};