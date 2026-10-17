class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<pair<int,int>,int>> v(n);
        
        for(int i=0;i<n;++i){
            int sum=0,temp=nums[i];
            while(temp){
                sum+=temp%10;
                temp/=10;
            }
            v[i]={{sum,nums[i]},i};
        }
        
        sort(v.begin(),v.end());
        
        int swaps=0;
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;++i){
            if(visited[i]||v[i].second==i)continue;
            
            int cycle=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=v[j].second;
                cycle++;
            }
            if(cycle>1)swaps+=(cycle-1);
        }
        
        return swaps;
    }
};