class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int is[210]={0};
       
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(is[nums[i]+100]==0)
            {
                k++;
                is[nums[i]+100]=1;
            }
        }
        int p=0;
            for(int j=0;j<203;j++)
                if(is[j])
                    {nums[p]=j-100;
                    p++;}
        return k;
                
       
    }
};