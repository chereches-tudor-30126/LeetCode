class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> res(n);
        int depth = 0;
        
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                res[i] = depth % 2;
                depth++;
            } else {
                depth--;
                res[i] = depth % 2;
            }
        }
        
        return res;
    }
};