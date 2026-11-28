class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1, 0), mult(n + 1, 0);
        for (auto& x : items) cnt[x[0]]++;
        
        for (int i = 1; i <= n; ++i) {
            if (!cnt[i]) continue;
            for (int j = i; j <= n; j += i) {
                mult[i] += cnt[j];
            }
        }
        
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        long long cheapest = items[0][1];
        long long rem = budget, ans = 0;
        
        for (auto& x : items) {
            long long p = x[1];
            if (p >= 2 * cheapest) break;
            long long can_buy = min((long long)mult[x[0]] - 1, rem / p);
            ans += can_buy * 2;
            rem -= can_buy * p;
        }
        
        return ans + rem / cheapest;
    }
};