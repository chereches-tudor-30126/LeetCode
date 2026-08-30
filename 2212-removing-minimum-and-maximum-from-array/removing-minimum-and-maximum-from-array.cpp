class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_nr=nums[0];
        int max_nr=nums[0];
        int min_pos=0,max_pos=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<min_nr){
                min_nr=nums[i];
                min_pos=i;
            }
            if(nums[i]>max_nr){
                max_nr=nums[i];
                max_pos=i;
            }
        }
        int left,mid,right;
        left=min(min_pos,max_pos);
        right=max(min_pos,max_pos);
        return min({ right + 1, (int)nums.size() - left, (left + 1) + ((int)nums.size() - right) });
        
    }
};