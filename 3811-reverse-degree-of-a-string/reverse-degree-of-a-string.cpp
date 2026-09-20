class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int pos=0;
        for(char c : s){
            ++pos;
            ans+=(pos*(26-(c-'a')));
        }
        return ans;
    }
};