class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int is[52]={0};
        for (int x:nums){
            is[x]++;
        }
        int s=nums[0];
        int l=0;

        while (l<nums.size()-1 && nums[l+1]==nums[l]+1){
            s+=nums[l+1];
            l++;
        }
        while (s<=50 && is[s]>0){
            s++;
        }
        return s;
    }
};