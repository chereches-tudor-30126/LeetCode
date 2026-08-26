class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones_pos;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            ones_pos.push_back(i);
        }
    }
    if (ones_pos.size()<k){
        return "";
    }
    string ans="";
    int min_len=s.length()+1;
    for (int i=0;i<=ones_pos.size()-k;i++){
        int left=ones_pos[i];
        int right=ones_pos[i+k-1];
        int current_len=right-left + 1;
        string current_str=s.substr(left, current_len);
        if (current_len<min_len){
            min_len=current_len;
            ans=current_str;
        } else if(current_len == min_len){
            if (current_str<ans){
                ans=current_str;
            }
        }
    }
    
    return ans;
    }
};