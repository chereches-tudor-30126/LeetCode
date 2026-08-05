class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int index=0;
        while(index<=right)
        {
            if(nums[index]==0)
                {
                    int aux=nums[left];
                    nums[left]=nums[index];
                    nums[index]=aux;
                    left++;
                    index++;
                }
            else
            if(nums[index]==2)
            {
                int aux=nums[right];
                nums[right]=nums[index];
                nums[index]=aux;
                right--;
            }
            else
            if(nums[index]==1)
            index++;
           
        }
    }
};