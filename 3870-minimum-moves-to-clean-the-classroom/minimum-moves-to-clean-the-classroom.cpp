class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(),n=classroom[0].size(),sr=-1,sc=-1,l=0;
        vector<pair<int,int>>ls;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }else if(classroom[i][j]=='L'){
                    ls.push_back({i,j});
                }
            }
        }
        l=ls.size();
        if(!l)return 0;
        vector<int>me(409600,-1);
        queue<tuple<int,int,int,int,int>>q;
        q.push({0,sr,sc,0,energy});
        me[sr*20480+sc*1024]=energy;
        int d[]={-1,0,1,0,-1};
        while(!q.empty()){
            auto[v,r,y,k,g]=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int nr=r+d[i],ny=y+d[i+1];
                if(nr>=0&&nr<m&&ny>=0&&ny<n&&classroom[nr][ny]!='X'){
                    int ng=g-1;
                    if(ng<0)continue;
                    int nk=k;
                    if(classroom[nr][ny]=='R'){
                        ng=energy;
                    }else if(classroom[nr][ny]=='L'){
                        for(int j=0;j<l;++j){
                            if(ls[j].first==nr&&ls[j].second==ny){
                                nk|=1<<j;
                            }
                        }
                    }
                    if(nk==(1<<l)-1)return v+1;
                    int idx=nr*20480+ny*1024+nk;
                    if(ng>me[idx]){
                        me[idx]=ng;
                        q.push({v+1,nr,ny,nk,ng});
                    }
                }
            }
        }
        return -1;
    }
};