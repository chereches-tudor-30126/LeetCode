class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            
            int val = num % k;
            next_dp[val] += 1;
            
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_r = (r * val) % k;
                    next_dp[new_r] += dp[r];
                }
            }
            
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }
            
            dp = next_dp;
        }
        
        return result;
    }
};