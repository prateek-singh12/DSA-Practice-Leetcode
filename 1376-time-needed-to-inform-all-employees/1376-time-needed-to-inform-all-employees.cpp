class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>> q;  // {employeeID, timeTakenSoFar}
        q.push({headID, 0});
        int maxTime = 0;

        while (!q.empty()) {
            auto [node, timeSoFar] = q.front();
            q.pop();

            maxTime = max(maxTime, timeSoFar);

            for (int sub : adj[node]) {
                q.push({sub, timeSoFar + informTime[node]});
            }
        }

        return maxTime;
    }
};

// class Solution {
// public:
//     int dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& informTime) {
//         int maxSubTime = 0;
        
//         for (int sub : adj[node]) {
//             maxSubTime = max(maxSubTime, dfs(sub, adj, informTime));
//         }

//         return informTime[node] + maxSubTime;
//     }

//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
//         unordered_map<int, vector<int>> adj;

//         for (int i = 0; i < n; ++i) {
//             if (manager[i] != -1) {
//                 adj[manager[i]].push_back(i);
//             }
//         }

//         return dfs(headID, adj, informTime);
//     }
// };
