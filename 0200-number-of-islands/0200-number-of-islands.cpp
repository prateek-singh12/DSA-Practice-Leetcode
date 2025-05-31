// class Solution {
// public:

//     void dfs(vector<vector<char>>& grid, int i, int j){
//         int m= grid.size(); //row
//         int n= grid[0].size(); //col
//         if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1'){
//             return;
//         }
//         grid[i][j]='v'; //mark visited
//         dfs(grid,i+1,j);
//         dfs(grid,i-1,j);
//         dfs(grid,i,j+1);
//         dfs(grid,i,j-1);
//     }

//     int numIslands(vector<vector<char>>& grid) {

//         int m= grid.size(); //row
//         int n= grid[0].size(); //col
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     dfs(grid,i,j);
//                     ans++;
//                 }
//             }
//         }
//         return ans;
        
//     }
// };

//bfs
class Solution {
public:
    int numIslands( vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 'v'; // Mark as visited

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto [dx, dy] : directions) {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1'){
                                q.push({nx, ny});
                                grid[nx][ny] = 'v'; // Mark as visited
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
