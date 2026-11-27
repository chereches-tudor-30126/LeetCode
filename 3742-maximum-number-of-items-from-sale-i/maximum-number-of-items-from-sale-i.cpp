class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free_cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free_cnt[i]++;
                }
            }
        }
        
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int first_val = 1 + free_cnt[i];
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + first_val);
            }
            for (int b = price; b <= budget; ++b) {
                dp[b] = max(dp[b], dp[b - price] + 1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};