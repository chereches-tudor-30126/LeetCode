class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> tin(n),tout(n),depth(n),bit(n+2,0);
        vector<vector<int>> up(n,vector<int>(16));
        int timer=0;
        
        auto dfs=[&](auto& self,int u,int p,int d)->void{
            tin[u]=++timer;
            depth[u]=d;
            up[u][0]=p;
            for(int i=1;i<16;++i)up[u][i]=up[up[u][i-1]][i-1];
            for(int v:adj[u])if(v!=p)self(self,v,u,d+1);
            tout[u]=timer;
        };
        dfs(dfs,0,0,0);
        
        for(int i=0;i<n;++i){
            int val=1<<(s[i]-'a');
            for(int j=tin[i];j<=n;j+=j&-j)bit[j]^=val;
            for(int j=tout[i]+1;j<=n;j+=j&-j)bit[j]^=val;
        }
        
        vector<bool> ans;
        for(string& q:queries){
            if(q[0]=='u'){
                int u; char c;
                sscanf(q.c_str(),"update %d %c",&u,&c);
                int val=(1<<(s[u]-'a'))^(1<<(c-'a'));
                s[u]=c;
                for(int j=tin[u];j<=n;j+=j&-j)bit[j]^=val;
                for(int j=tout[u]+1;j<=n;j+=j&-j)bit[j]^=val;
            }else{
                int u,v;
                sscanf(q.c_str(),"query %d %d",&u,&v);
                int mask=0;
                for(int j=tin[u];j>0;j-=j&-j)mask^=bit[j];
                for(int j=tin[v];j>0;j-=j&-j)mask^=bit[j];
                
                int x=u,y=v;
                if(depth[x]<depth[y])swap(x,y);
                for(int i=15;i>=0;--i){
                    if(depth[x]-(1<<i)>=depth[y])x=up[x][i];
                }
                if(x!=y){
                    for(int i=15;i>=0;--i){
                        if(up[x][i]!=up[y][i]){
                            x=up[x][i];
                            y=up[y][i];
                        }
                    }
                    x=up[x][0];
                }
                
                mask^=(1<<(s[x]-'a'));
                ans.push_back((mask&(mask-1))==0);
            }
        }
        
        return ans;
    }
    
};