class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> ans(m,string(n,'#'));
        
        for(int j=0;j<n;++j){
            ans[0][j]='.';
        }
        for(int i=1;i<m;++i){
            ans[i][n-1]='.';
        }
        
        return ans; 
    }
};