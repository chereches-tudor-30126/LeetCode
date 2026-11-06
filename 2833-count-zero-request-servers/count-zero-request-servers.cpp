class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=queries.size();
        vector<pair<int,int>> q(m);
        for(int i=0;i<m;++i)q[i]={queries[i],i};
        sort(q.begin(),q.end());
        
        sort(logs.begin(),logs.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });
        
        vector<int> ans(m),freq(n+1,0);
        int l=0,r=0,cnt=0,k=logs.size();
        
        for(int i=0;i<m;++i){
            int end=q[i].first,start=end-x,idx=q[i].second;
            
            while(r<k&&logs[r][1]<=end){
                if(freq[logs[r][0]]++==0)cnt++;
                r++;
            }
            while(l<k&&logs[l][1]<start){
                if(--freq[logs[l][0]]==0)cnt--;
                l++;
            }
            
            ans[idx]=n-cnt;
        }
        
        return ans;
    }
};