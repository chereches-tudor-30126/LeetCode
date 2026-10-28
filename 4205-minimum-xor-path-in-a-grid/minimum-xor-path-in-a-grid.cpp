class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> dp(n,vector<bool>(1024,false));
        
        for(int i=0;i<m;++i){
            vector<vector<bool>> next_dp(n,vector<bool>(1024,false));
            for(int j=0;j<n;++j){
                if(i==0&&j==0){
                   next_dp[0][grid[0][0]]=true;
                    continue;
                }
                for(int x=0;x<1024;++x){
                    if(i>0&&dp[j][x]){
                        next_dp[j][x^grid[i][j]]=true;
                    }
                    if(j>0&&next_dp[j-1][x]){
                        next_dp[j][x^grid[i][j]]=true;
                    }
                }
            }
            dp=next_dp;
        }
        
        for(int x=0;x<1024;++x){
            if(dp[n-1][x]){
                return x;
            }
        }
        
        return 0;
    }
    
};