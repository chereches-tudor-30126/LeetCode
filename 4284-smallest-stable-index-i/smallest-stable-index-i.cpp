class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int max_num=nums[0];
        int min_num=nums[nums.size()-1];
        vector<int> left(n);
        vector<int> right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<nums.size();++i){
            if(nums[i]>max_num){
                max_num=nums[i];
            }
            left[i]=max_num;
        }
        for(int i=n-2;i>=0;--i){
            if(nums[i]<min_num){
                min_num=nums[i];
            }
            right[i]=min_num;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(left[i]-right[i]<=k)
                return i;
        }
        return -1;
    }
};