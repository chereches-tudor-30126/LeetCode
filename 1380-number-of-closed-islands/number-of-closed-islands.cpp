class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    bool isClosed=true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]=1;
                    
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        
                        int r=p.first;
                        int c=p.second;
                        
                        if(r==0||r==n-1||c==0||c==m-1){
                            isClosed=false;
                        }
                        
                        int dr[]={-1,1,0,0};
                        int dc[]={0,0,-1,1};
                        
                        for(int k=0;k<4;++k){
                            int nr=r+dr[k];
                            int nc=c+dc[k];
                            
                            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==0){
                                grid[nr][nc]=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                    if(isClosed)ans++;
                }
            }
        }
        
        return ans;
    }
};