class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9); 
        int ans = 1e9;
        int left = 0;
        int current_sum = 0;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            if (current_sum == target) {
                int current_length = right - left + 1;
                
                if (left > 0 && min_len[left - 1] != 1e9) {
                    ans = min(ans, current_length + min_len[left - 1]);
                }
                
                min_len[right] = current_length;
            }
            
            if (right > 0) {
                min_len[right] = min(min_len[right], min_len[right - 1]);
            }
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};