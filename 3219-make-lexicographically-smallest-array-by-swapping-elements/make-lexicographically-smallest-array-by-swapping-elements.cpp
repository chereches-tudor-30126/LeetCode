class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int, int>> valIdx(n);
        for (int i=0;i<n;++i){
            valIdx[i] = {nums[i], i};
        }
        sort(valIdx.begin(),valIdx.end());
        vector<int> ans(n);
        int i=0;
        while(i<n){
            int j=i+1;
            while (j<n && valIdx[j].first-valIdx[j-1].first<=limit){
                j++;
            }
            vector<int> indices;
            for (int k=i; k<j;++k){
                indices.push_back(valIdx[k].second);
            }
            sort(indices.begin(),indices.end());

            for (int k=i;k<j;++k){
                ans[indices[k-i]]=valIdx[k].first;
            }
            i=j;
        }
        
        return ans;
    }
};