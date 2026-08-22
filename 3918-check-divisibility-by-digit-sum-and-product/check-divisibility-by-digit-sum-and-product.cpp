class Solution {
public:
    bool checkDivisibility(int n) {
        int aux=n;
        int sum=0,prod=1;
        while(n){
            sum+=n%10;
            prod*=n%10;
            n/=10;
        }
        return aux%(sum+prod)==0;
        
    }
};