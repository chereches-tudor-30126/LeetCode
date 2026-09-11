class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int d[10]={0};
        for(int i=0;i<digits.size();++i){
            d[digits[i]]++;
        }
        int ans=0;
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                for(int k=0;k<=9;k++)
                    {
                        d[i]--;
                        d[j]--;
                        d[k]--;
                        if(k%2==0 && i!=0 && d[i]>=0 && d[j]>=0 && d[k]>=0)ans++;
                        d[i]++;
                        d[j]++;
                        d[k]++;
                    }
                            
                
                        
        return ans;
    }
};