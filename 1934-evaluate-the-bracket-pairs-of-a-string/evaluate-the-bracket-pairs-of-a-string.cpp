class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& k : knowledge) {
            dict[k[0]] = k[1];
        }
        
        string ans, key;
        bool inBracket = false;
        
        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key = "";
            } else if (c == ')') {
                inBracket = false;
                ans += dict.count(key) ? dict[key] : "?";
            } else if (inBracket) {
                key += c;
            } else {
                ans += c;
            }
        }
        
        return ans;
    }
};