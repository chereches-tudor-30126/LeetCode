class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        
        vector<vector<vector<pair<int, int>>>> dest(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1})));
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    dest[i][j][0] = {i, j};
                    dest[i][j][1] = {i, j};
                } else {
                    if (i + 1 < m) {
                        dest[i][j][0] = dest[i + 1][j][1];
                    }
                    if (j + 1 < n) {
                        dest[i][j][1] = dest[i][j + 1][0];
                    }
                }
            }
        }
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && dp[i][j] > 0) {
                    if (j + 1 < n) {
                        auto [ni, nj] = dest[i][j + 1][0];
                        if (ni != -1) {
                            dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                        }
                    }
                    if (i + 1 < m) {
                        auto [ni, nj] = dest[i + 1][j][1];
                        if (ni != -1) {
                            dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};