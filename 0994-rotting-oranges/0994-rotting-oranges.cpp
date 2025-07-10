// ROTTEN ORGANES - MULTI SOURCE BFS 0->EMPTY, 1->FRESH, 2->ROTTEN
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // if we dont want to do inplace then : vector<vector<int>> result=grid;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Edge case 1,2,3: all FRESH(return -1)  || all ROTTEN(0) ||All empty
        // cell(0)
        if (q.size() == m * n) {
            return 0; // all rotten
        }
        if (q.size() == 0) { // no rotten oranges
            // if all are empty return 0, but if even one fresh is present return -1;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        return -1;//fresh present
                    }
                }
            }
            return 0; //all empty 
        }

        int minutes = -1; // initialize answer with -1
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            int sz = q.size();
            minutes++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // mark as rotten
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Edge case 4: MIXED: At last if still FRESH orange left ->return -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};