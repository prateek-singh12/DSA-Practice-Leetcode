class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    void bfs(int start, unordered_map<int, vector<int>>& adj, vector<int>& mark,
             int& zero, int& one) {
        queue<int> q;
        q.push(start);
        mark[start] = 0; // root is level 0

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (mark[curr] == 0) {
                zero++;
            } else {
                one++;
            }

            for (int neighbor : adj[curr]) {
                if (mark[neighbor] == -1) {
                    mark[neighbor] = 1 - mark[curr]; // alternate marking
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        auto adjA = getAdj(edges1);
        auto adjB = getAdj(edges2);

        vector<int> markA(N, -1);
        int zeroA = 0, oneA = 0;
        bfs(0, adjA, markA, zeroA, oneA);

        vector<int> markB(M, -1);
        int zeroB = 0, oneB = 0;
        bfs(0, adjB, markB, zeroB, oneB);

        int maxFromTree2 = max(zeroB, oneB);

        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[i] = (markA[i] == 0 ? zeroA : oneA) +
                        maxFromTree2;
        }

        return result;
    }
};
