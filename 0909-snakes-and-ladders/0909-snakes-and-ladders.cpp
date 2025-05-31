class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int label = 1;

        // Mapping 1D positions to 2D (row, col)
        vector<pair<int, int>> position(n * n + 1);
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0); 

        for (int row = n - 1; row >= 0; row--) {
            for (int col : cols) {
                position[label++] = {row, col};
            }
            reverse(cols.begin(), cols.end()); 
        }

        vector<int> minMoves(n * n + 1, -1);
        minMoves[1] = 0;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int currentSquare = q.front();
            q.pop();

            for (int diceRoll = 1; diceRoll <= 6; diceRoll++) {
                int nextSquare = currentSquare + diceRoll;

                // If the move goes beyond the board, stop checking further dice
                // rolls
                if (nextSquare > n * n)
                    break;

                auto [row, col] = position[nextSquare];
                int finalDestination =
                    (board[row][col] != -1) ? board[row][col] : nextSquare;

                if (minMoves[finalDestination] == -1) {
                    minMoves[finalDestination] = minMoves[currentSquare] + 1;
                    q.push(finalDestination);
                }
            }
        }

        return minMoves[n * n];
    }
};
