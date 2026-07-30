class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int p2=1, p1=2;
        int c=0;
        for(int i=3;i<=n;i++)
        {
            c=p2+p1;
            p2=p1;
            p1=c;
        }
        return c;
    }
};