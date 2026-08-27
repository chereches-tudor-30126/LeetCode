class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();
        vector<int> count(26,0);
        for (char c:s){
            count[c-'a']++;
        }
        int L=0;
        while (L<n && count[target[L]-'a']>0){
            count[target[L]-'a']--;
            L++;
        }
        int start_i=L;
        if (start_i==n){
            start_i--;
            count[target[start_i]-'a']++;
        }
        for (int i=start_i;i>=0;--i){
            for (int c=target[i]-'a'+1;c<26;++c){
                if(count[c]>0){
                    string res=target.substr(0, i);
                    res+=(char)(c+'a');          
                    count[c]--; 
                    for (int j=0;j<26;++j){
                        res+=string(count[j],j+'a');
                    }
                    return res;
                }
            }
            if (i>0){
                count[target[i-1]-'a']++;
            }
        }
        return "";
    }
};