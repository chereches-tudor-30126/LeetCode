class Solution {
public:
    bool canAliceWin(int n) {
        int p=0;
        int last=10;
        while(n-last>=0){
            n-=last;
            last--;
            p++;
        }
        return p%2==1;
    }
};