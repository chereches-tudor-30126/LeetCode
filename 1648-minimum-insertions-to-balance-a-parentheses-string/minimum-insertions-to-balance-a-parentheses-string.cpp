class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needRight = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                if (needRight % 2 != 0) {
                    insertions++;
                    needRight--;
                }
                needRight += 2;
            } else {
                needRight--;
                if (needRight < 0) {
                    insertions++;
                    needRight += 2;
                }
            }
        }
        
        return insertions + needRight;
    }
};