class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q; //pair to keep track of coordinates to apply manhattan

        // MULTI-SOURCE BFS
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // Edge case: NO land or|| NO water
        if (q.empty() || q.size() == n * n) {
            return -1;
        }

        int maxDist = -1;
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        //multi bfs
        while (!q.empty()) {
            int sz = q.size();
            ++maxDist;

            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // mark as visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return maxDist;
    }
};
