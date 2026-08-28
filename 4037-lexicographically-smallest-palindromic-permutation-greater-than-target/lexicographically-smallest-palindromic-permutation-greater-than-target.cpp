class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.length();
        vector<int> freq(26,0);
    for (char c:s){
        freq[c-'a']++;
    }
    int odds=0;
    string mid_char="";
    vector<int> half_freq(26,0);
    for (int i=0;i<26;i++){
        if (freq[i]%2!=0){
            odds++;
            mid_char=string(1,'a'+i);
        }
        half_freq[i]=freq[i]/2;
    }

    if (odds>1 || (n%2==0 && odds>0)){
        return "";
    }

    int half_len=n/2;
    string T_H=target.substr(0,half_len);

    auto can_form=[&](const string& prefix){
        vector<int> pfreq(26,0);
        for (char c:prefix) pfreq[c-'a']++;
        for (int i=0;i<26;i++){
            if (pfreq[i]>half_freq[i]) return false;
        }
        return true;
    };

    if (can_form(T_H)){
        string right_half=T_H;
        reverse(right_half.begin(),right_half.end());
        string P=T_H+mid_char+right_half;
        if (P>target){
            return P;
        }
    }

    for (int i=half_len-1;i>=0;i--){
        string prefix=T_H.substr(0,i);
        if (!can_form(prefix)) continue;
        vector<int> rem_freq=half_freq;
        for (char c:prefix){
            rem_freq[c-'a']--;
        }

        char best_c=0;
        for (int c=T_H[i]-'a'+1;c<26;c++){
            if (rem_freq[c]>0){
                best_c='a'+c;
                break;
            }
        }

        if (best_c!=0){
            rem_freq[best_c-'a']--;
            string H=prefix+best_c;

            for(int c=0;c<26;c++){
                while(rem_freq[c]>0){
                    H+=(char)('a'+c);
                    rem_freq[c]--;
                }
            }

         
            string right_half=H;
            reverse(right_half.begin(),right_half.end());
            return H+mid_char+right_half;
        }
    }

    return "";
    }
};