class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()-1,m=nums2.size()-1;int m_le=0;
        int i=0,j=0;
        while(i<=n && j<=m){
            if(nums1[i]<=nums2[j]){
                if(j-i>m_le)m_le=j-i;
                j++;
            }
            else
            i++;
        }
        return m_le;
     
    }
};