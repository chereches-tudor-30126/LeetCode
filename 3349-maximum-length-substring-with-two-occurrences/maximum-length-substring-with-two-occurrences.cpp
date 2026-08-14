class Solution {
public:
    int maximumLengthSubstring(string s) {
        int is[26]={0};
        int m=0;
        int l=0, r=0;
        
        while(r<s.size()){
            is[s[r]-'a']++;
            while (is[s[r]-'a']>2) 
            {
                is[s[l]-'a']--; 
                l++;
            }
           
            if(r-l+1>m){
                m=r-l+1;
            }
            r++;
        }
        
        return m;
    }
    
};