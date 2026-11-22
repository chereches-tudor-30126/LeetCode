class Solution {
public:
    bool checkString(string s) {
        bool ok=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                ok=true;
            }
            if(s[i]=='a' && ok){
                return false;
            }
        }
        return true;
    }
};