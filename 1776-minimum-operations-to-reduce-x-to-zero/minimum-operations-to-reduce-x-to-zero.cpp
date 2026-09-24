class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0, n = nums.size();
        for (int num : nums) totalSum += num;
        
        int target = totalSum - x;
        if (target < 0) return -1;
        if (target == 0) return n;
        
        int maxLength = -1, currentSum = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            
            while (currentSum > target && left <= right) {
                currentSum -= nums[left++];
            }
            
            if (currentSum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        return maxLength == -1 ? -1 : n - maxLength;
    }
};