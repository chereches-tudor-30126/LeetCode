class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        int n=piles.size();
        vector<int> suffixSum(n,0);
        suffixSum[n-1]=piles[n-1];
        for (int i=n-2; i>=0; --i) {
            suffixSum[i]=suffixSum[i+1]+piles[i];
        }
        vector<vector<int>> memo(n,vector<int>(n+1,-1));
        
        return dfs(0,1,n,suffixSum,memo);
    }
    
private:
    int dfs(int i, int m, int n, const vector<int>& suffixSum, vector<vector<int>> &memo){
        if (i>=n) {
            return 0;
        }
     
        if (i+2*m>=n) {
            return suffixSum[i];
        }
     
        if (memo[i][m]!=-1) {
            return memo[i][m];
        }
        
        int max_stones=0;
    
        for (int x=1;x<=2*m;++x) {
    
            int current_score=suffixSum[i]-dfs(i+x,max(m,x),n,suffixSum,memo);
            max_stones = max(max_stones,current_score);
        }
        return memo[i][m]=max_stones;
    }
};