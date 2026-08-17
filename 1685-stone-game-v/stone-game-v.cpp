class Solution {
    vector<vector<int>> memo;
    vector<int> pref;
    
    int solve(int i, int j) {
        if(i==j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int max_score=0;
        for (int k=i;k<j;++k){
            int leftSum=pref[k+1]-pref[i];
            int rightSum=pref[j+1]-pref[k+1];
            if (leftSum<rightSum){
                max_score=max(max_score,leftSum+solve(i,k));
            }else if(leftSum>rightSum){
                max_score=max(max_score,rightSum+solve(k+1,j));
            }else{
                max_score=max({max_score,leftSum+solve(i,k),rightSum+solve(k+1,j)});
            }
        }
        return memo[i][j]=max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue){
        int n=stoneValue.size();
        memo.assign(n,vector<int>(n,-1));
        pref.assign(n+1,0);
        for(int i=0;i<n;++i){
            pref[i+1]=pref[i]+stoneValue[i];
        }
        return solve(0,n-1);
    }
};