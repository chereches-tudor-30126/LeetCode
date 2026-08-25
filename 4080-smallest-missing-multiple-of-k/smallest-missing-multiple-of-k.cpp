class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int freq[101]={0};
        for(int i=0;i<nums.size();++i){
            if(nums[i]%k==0)
                freq[nums[i]/k]++;
        }
        for(int i=1;i<=100;++i)
            if(freq[i]==0)
                return i*k;
        return 101;
    }
};