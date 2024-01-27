class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1000000007;

    // 3D DP array to store the number of ways to reach each cell with a certain number of moves
    vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));

    // Base case: the starting position has 1 way with 0 moves
    dp[0][startRow][startColumn] = 1;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int count = 0;

    // Iterate through the number of moves
    for (int move = 1; move <= maxMove; ++move) {
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                // Calculate the number of ways to reach the current cell from its neighbors in the previous move
                for (const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                        dp[move][row][col] = (dp[move][row][col] + dp[move - 1][newRow][newCol]) % MOD;
                    } else {
                        // If the ball moves out of the grid, increment the count
                        count = (count + dp[move - 1][row][col]) % MOD;
                    }
                }
            }
        }
    }

    return count;
    }
};
