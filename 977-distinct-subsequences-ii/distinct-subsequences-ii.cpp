class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD=1e9+7;
        vector<long long> dp(26,0);
        long long ans=0;
        for(char c:s){
            int idx=c-'a';
            long long old_val=dp[idx];
            dp[idx]=(ans+1)%MOD;
            ans=(ans+dp[idx]-old_val+MOD) % MOD;
        }
        return ans;
    }
};