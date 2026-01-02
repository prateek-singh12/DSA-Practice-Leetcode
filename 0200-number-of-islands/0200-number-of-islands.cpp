class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid){
        int m= grid.size(); //no of rows
        int n= grid[0].size(); //no of col
        if(i<0 || j<0 || i>=m ||j >=n || grid[i][j] != '1'){
            return;
        }
        grid[i][j]='v';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size(); //no of rows
        int n= grid[0].size(); //no of col
        int ans=0;
        //no need for visited we can use grid as visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// //bfs
// class Solution {
// public:
//     int numIslands( vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int count = 0;

//         vector<pair<int, int>> directions = {
//             {1, 0}, {-1, 0}, {0, 1}, {0, -1}
//         };

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == '1') {
//                     ++count;
//                     queue<pair<int, int>> q;
//                     q.push({i, j});
//                     grid[i][j] = 'v'; // Mark as visited

//                     while (!q.empty()) {
//                         auto [x, y] = q.front();
//                         q.pop();

//                         for (auto [dx, dy] : directions) {
//                             int nx = x + dx;
//                             int ny = y + dy;

//                             if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1'){
//                                 q.push({nx, ny});
//                                 grid[nx][ny] = 'v'; // Mark as visited
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         return count;
//     }
// };
