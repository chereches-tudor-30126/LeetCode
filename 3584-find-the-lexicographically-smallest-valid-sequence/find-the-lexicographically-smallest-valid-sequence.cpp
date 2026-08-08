class Solution{
public:
    vector<int> validSequence(string word1, string word2){
        int n = word1.length(), m = word2.length();

        vector<int> right_match(m+1,-1);
        right_match[m]=n;
        int p=n-1;
        for (int j=m-1;j>=0;--j){
            while (p>=0 && word1[p]!=word2[j]){
                p--;
            }
            if (p>=0){
                right_match[j]=p;
                p--;
            }
        }
        
        vector<int> ans;
        bool changed=false;
        int j=0;
        
        for (int i=0; i<n && j<m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed && right_match[j+1]>=i+1){
                ans.push_back(i);
                changed=true;
                j++;
            }
        }
        
        if (ans.size()==m){
            return ans;
        }
        
        return {}; 
    }
};