class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == 1) {
            int is[51] = {0};
            for (int i = 0; i < nums.size(); ++i)
                is[nums[i]]++;
            for (int i = 50; i >= 0; --i)
                if (is[i] == 1)
                    return i;
            return -1;
        }
        else
        if(k==nums.size()){
            int m=-1;
            for(int i=0;i<nums.size();++i)
                if(nums[i]>m) m=nums[i];
            return m;
        }
        else{
            int n = nums.size();
            int c1 = 0, c2 = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] == nums[0]) c1++;
                if(nums[i] == nums[n - 1]) c2++;
            }
            
            int ans = -1;
            if(c1 == 1) {
                ans = max(ans, nums[0]);
            }
            if(c2 == 1) {
                ans = max(ans, nums[n - 1]);
            }
            
            return ans;
        }
    }
};