class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even=0,odd=0;
        int m=nums1[0];
        for(int i=0;i<nums1.size();++i){
            if(nums1[i]%2==0)
                even++;
            else
                odd++;
            if(nums1[i]<m)m=nums1[i];
        }
        if(m%2==1)return true;
        
        return !odd;
    }
};