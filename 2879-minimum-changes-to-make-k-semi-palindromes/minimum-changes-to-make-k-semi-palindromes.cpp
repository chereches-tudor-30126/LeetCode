class Solution {
public:
    int minimumChanges(string s, int k) {
       int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int changes = 0;
                        for (int rem = 0; rem < d; ++rem) {
                            int l = i + rem;
                            int r = j - d + 1 + rem;
                            while (l < r) {
                                if (s[l] != s[r]) changes++;
                                l += d;
                                r -= d;
                            }
                        }
                        cost[i][j] = min(cost[i][j], changes);
                    }
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) {
                for (int j = 2 * (p - 1); j <= i - 2; ++j) {
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }
        
        return dp[n][k]; 
    }
};