class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[] = {0, 0, 1, -1}; // right, left, down, up
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == initialColor) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};
