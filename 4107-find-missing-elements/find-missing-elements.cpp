class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int is[101]={0},min=101,max=-1;
        for(int i=0;i<nums.size();i++)
            {if(nums[i]<min)
                min=nums[i];
            if(nums[i]>max)
                max=nums[i];
            is[nums[i]]++;
            }
        vector<int> sol;
        for(int i=min;i<=max;i++)
            if(is[i]==0)
                sol.push_back(i);
        return sol;
    }
};