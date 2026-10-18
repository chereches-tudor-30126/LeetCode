class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        long long MOD=1e9+7;
        vector<vector<long long>> C(n+1,vector<long long>(n+1,0));
        
        for(int i=0;i<=n;++i){
            C[i][0]=1;
            for(int j=1;j<=i;++j){
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
            }
        }
        
        function<long long(vector<int>&)> solve=[&](vector<int>& arr)->long long{
            int sz=arr.size();
            if(sz<=2)return 1;
            
            vector<int> left,right;
            int root=arr[0];
            
            for(int i=1;i<sz;++i){
                if(arr[i]<root)left.push_back(arr[i]);
                else right.push_back(arr[i]);
            }
            
            long long l=solve(left);
            long long r=solve(right);
            long long comb=C[left.size()+right.size()][left.size()];
            
            return (((comb*l)%MOD)*r)%MOD;
        };
        
        return (solve(nums)-1+MOD)%MOD;
    }
};