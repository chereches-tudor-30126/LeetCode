class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]={0,0,0};
        for (int s:stones){
            cnt[s%3]++;
        }
        int c0=cnt[0];
        int c1=cnt[1];
        int c2=cnt[2];
        if (c0%2==0){
            return c1>=1 && c2>=1;
        }else{
            return abs(c1-c2)>2;
        }
    }
};