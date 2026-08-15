class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool is_zero=true;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0)
                is_zero=false;
            ans=ans^nums[i];
        }
        if(is_zero)return 0;
        if(ans)return nums.size();
        else return nums.size()-1;
    }
};