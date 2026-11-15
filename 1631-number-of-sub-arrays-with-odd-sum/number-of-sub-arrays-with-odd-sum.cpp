class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0, sum = 0, ans = 0, MOD = 1e9 + 7;
        for (int x : arr) {
            sum += x;
            if (sum % 2 == 0) {
                ans = (ans + odd) % MOD;
                even++;
            } else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        return ans;
    }
};