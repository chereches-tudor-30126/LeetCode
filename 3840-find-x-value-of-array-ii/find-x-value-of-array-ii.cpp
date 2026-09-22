class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prod(2 * n, 1);
        vector<vector<int>> cnt(2 * n, vector<int>(k, 0));
        
        for (int i = 0; i < n; i++) {
            prod[n + i] = nums[i] % k;
            cnt[n + i][nums[i] % k] = 1;
        }
        
        for (int i = n - 1; i > 0; i--) {
            prod[i] = (prod[i << 1] * prod[i << 1 | 1]) % k;
            for (int j = 0; j < k; j++) {
                cnt[i][j] = cnt[i << 1][j];
            }
            for (int j = 0; j < k; j++) {
                if (cnt[i << 1 | 1][j]) {
                    cnt[i][(prod[i << 1] * j) % k] += cnt[i << 1 | 1][j];
                }
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            
            int p = idx + n;
            prod[p] = val % k;
            fill(cnt[p].begin(), cnt[p].end(), 0);
            cnt[p][val % k] = 1;
            
            for (p >>= 1; p > 0; p >>= 1) {
                prod[p] = (prod[p << 1] * prod[p << 1 | 1]) % k;
                fill(cnt[p].begin(), cnt[p].end(), 0);
                for (int j = 0; j < k; j++) {
                    cnt[p][j] = cnt[p << 1][j];
                }
                for (int j = 0; j < k; j++) {
                    if (cnt[p << 1 | 1][j]) {
                        cnt[p][(prod[p << 1] * j) % k] += cnt[p << 1 | 1][j];
                    }
                }
            }
            
            if (start >= n || x >= k) {
                ans.push_back(0);
                continue;
            }
            
            vector<int> L, R;
            for (int l = start + n, r = n - 1 + n; l <= r; l >>= 1, r >>= 1) {
                if (l & 1) L.push_back(l++);
                if (!(r & 1)) R.push_back(r--);
            }
            
            long long curr_p = 1;
            int count_x = 0;
            
            for (int node : L) {
                for (int j = 0; j < k; j++) {
                    if (cnt[node][j] && (curr_p * j) % k == x) {
                        count_x += cnt[node][j];
                    }
                }
                curr_p = (curr_p * prod[node]) % k;
            }
            for (int i = R.size() - 1; i >= 0; i--) {
                int node = R[i];
                for (int j = 0; j < k; j++) {
                    if (cnt[node][j] && (curr_p * j) % k == x) {
                        count_x += cnt[node][j];
                    }
                }
                curr_p = (curr_p * prod[node]) % k;
            }
            
            ans.push_back(count_x);
        }
        
        return ans;
    }
};