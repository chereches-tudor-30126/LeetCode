class Solution{
    int dp[65][45],F2[10]={0,0,1,0,2,0,1,0,3,0},F3[10]={0,0,0,1,0,0,1,0,0,2},F5[10]={0,0,0,0,0,1,0,0,0,0},F7[10]={0,0,0,0,0,0,0,1,0,0};
    void init(){
        for(int i=0;i<65;++i)for(int j=0;j<45;++j)dp[i][j]=1e9;
        dp[0][0]=0;
        for(int i=0;i<=60;++i)for(int j=0;j<=40;++j)if(dp[i][j]!=1e9)
            for(int d=2;d<=9;++d)if(d!=5&&d!=7)dp[min(60,i+F2[d])][min(40,j+F3[d])]=min(dp[min(60,i+F2[d])][min(40,j+F3[d])],dp[i][j]+1);
        for(int i=60;i>=0;--i)for(int j=40;j>=0;--j){
            if(i<60)dp[i][j]=min(dp[i][j],dp[i+1][j]);
            if(j<40)dp[i][j]=min(dp[i][j],dp[i][j+1]);
        }
    }
public:
    string smallestNumber(string num,long long t){
        long long temp=t;int r2=0,r3=0,r5=0,r7=0,n=num.length(),fz=n;
        while(temp%2==0){r2++;temp/=2;}
        while(temp%3==0){r3++;temp/=3;}
        while(temp%5==0){r5++;temp/=5;}
        while(temp%7==0){r7++;temp/=7;}
        if(temp>1)return "-1";
        init();
        vector<int> p2(n+1,r2),p3(n+1,r3),p5(n+1,r5),p7(n+1,r7);
        for(int i=0;i<n;++i){
            if(num[i]=='0'){fz=i;break;}
            int d=num[i]-'0';
            p2[i+1]=max(0,p2[i]-F2[d]);p3[i+1]=max(0,p3[i]-F3[d]);
            p5[i+1]=max(0,p5[i]-F5[d]);p7[i+1]=max(0,p7[i]-F7[d]);
        }
        if(fz==n&&!p2[n]&&!p3[n]&&!p5[n]&&!p7[n])return num;
        for(int i=min(n-1,fz);i>=0;--i)for(int d=max(1,num[i]-'0'+1);d<=9;++d){
            int m2=max(0,p2[i]-F2[d]),m3=max(0,p3[i]-F3[d]),m5=max(0,p5[i]-F5[d]),m7=max(0,p7[i]-F7[d]),L=n-1-i;
            if(m5+m7+dp[m2][m3]<=L){
                string ans=num.substr(0,i)+to_string(d);
                for(int k=i+1;k<n;++k)for(int c=1;c<=9;++c){
                    int nm2=max(0,m2-F2[c]),nm3=max(0,m3-F3[c]),nm5=max(0,m5-F5[c]),nm7=max(0,m7-F7[c]);
                    if(nm5+nm7+dp[nm2][nm3]<=n-1-k){
                        ans+=to_string(c);m2=nm2;m3=nm3;m5=nm5;m7=nm7;break;
                    }
                }
                return ans;
            }
        }
        int M=max(n+1,r5+r7+dp[r2][r3]);string ans="";
        for(int k=0;k<M;++k)for(int c=1;c<=9;++c){
            int nm2=max(0,r2-F2[c]),nm3=max(0,r3-F3[c]),nm5=max(0,r5-F5[c]),nm7=max(0,r7-F7[c]);
            if(nm5+nm7+dp[nm2][nm3]<=M-1-k){
                ans+=to_string(c);r2=nm2;r3=nm3;r5=nm5;r7=nm7;break;
            }
        }
        return ans;
    }
};