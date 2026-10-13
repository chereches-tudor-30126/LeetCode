class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        for (int i = 0; i < n; ++i) {
            squares[i] = 1LL * nums[i] * nums[i];
        }
        
        
        sort(squares.rbegin(), squares.rend());
        
        long long max_score = 0;
        int num_positives = (n + 1) / 2; 
        for (int i = 0; i < n; ++i) {
            if (i < num_positives) {
                max_score += squares[i];
            } else {
                max_score -= squares[i];
            }
        }
        
        return max_score;
    }
};