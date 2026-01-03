class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int column, int color, int originalcolor){
        int n=image.size();
        int m=image[0].size();
        if(row<0 || column<0 || row>=n || column >=m || image[row][column]!=originalcolor){
            return;
        }
        image[row][column]=color;
        dfs(image, row + 1, column, color, originalcolor); // Down
        dfs(image, row - 1, column, color, originalcolor); // Up
        dfs(image, row, column + 1, color, originalcolor); // Right
        dfs(image, row, column - 1, color, originalcolor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor=image[sr][sc];
        if(color!=originalcolor){
            //image[sr][sc]=color;
            dfs(image,sr,sc,color,originalcolor);
        }
        return image;

    }
};

// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int m = image.size(), n = image[0].size();
//         int originalColor = image[sr][sc];
//         // if we dont want to do inplace then : vector<vector<int>> result=image;
//         if (originalColor == color) return image;

//         queue<pair<int, int>> q;
//         q.push({sr, sc});
//         image[sr][sc] = color;

//         vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//         while (!q.empty()) {
//             int sz = q.size();
//             while (sz--) {
//                 auto [x, y] = q.front(); 
//                 q.pop();

//                 for (auto [dx, dy] : directions) {
//                     int nx = x + dx, ny = y + dy;

//                     if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == originalColor) {
//                         image[nx][ny] = color;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//         }

//         return image;
//     }
// };



// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
//                                   int color) {
//         int m = image.size();
//         int n = image[0].size();
//         // if we dont want to do inplace then : vector<vector<int>> result=image;
//         int initialColor = image[sr][sc];
//         if (initialColor == color)
//             return image;

//         queue<pair<int, int>> q;
//         q.push({sr, sc});
//         image[sr][sc] = color;

//         int dx[] = {0, 0, 1, -1}; // right, left, down, up
//         int dy[] = {1, -1, 0, 0};

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();
//             for (int i = 0; i < 4; ++i) {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];

//                 if (nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == initialColor) {
//                     image[nx][ny] = color;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         return image;
//     }
// };