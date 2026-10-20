class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        long long ans = 0;
        
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool ok = true;
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int drop_pos = -1;
                
                for (int j = 0; j < k - 1; ++j) {
                    if (nums[i + j] > nums[i + j + 1]) {
                        drops++;
                        drop_pos = j;
                    }
                }
                
                if (drops > 1 || (drops == 1 && nums[i + k - 1] > nums[i])) {
                    ok = false;
                    break;
                }
                
                int start = (drops == 0) ? 0 : drop_pos + 1;
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (start + j) % k] != sorted_nums[i + j]) {
                        ok = false;
                        break;
                    }
                }
                
                if (!ok) break;
            }
            
            if (ok) {
                ans += k;
            }
        }
        
        return ans;
    }
};