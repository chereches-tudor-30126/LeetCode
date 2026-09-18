class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> L(26, -1), R(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (L[s[i] - 'a'] == -1) L[s[i] - 'a'] = i;
            R[s[i] - 'a'] = i;
        }
        
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (L[i] == -1) continue;
            int l = L[i], r = R[i];
            bool valid = true;
            for (int j = l; j <= r; ++j) {
                if (L[s[j] - 'a'] < l) { valid = false; break; }
                r = max(r, R[s[j] - 'a']);
            }
            if (valid) intervals.push_back({l, r});
        }
        
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.second == b.second ? (a.second - a.first) < (b.second - b.first) : a.second < b.second;
        });
        
        vector<string> res;
        int last_end = -1;
        for (auto& iv : intervals) {
            if (iv.first > last_end) {
                res.push_back(s.substr(iv.first, iv.second - iv.first + 1));
                last_end = iv.second;
            }
        }
        
        return res;
    }
};