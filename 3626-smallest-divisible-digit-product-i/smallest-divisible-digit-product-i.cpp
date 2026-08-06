class Solution {
public:
    int smallestNumber(int n, int t) {
        int last=n%10;
        int p=1;
        if(last==0)return n;
        int aux=n/10;
        while(aux){
            p=p*(aux%10);
            aux=aux/10;
            if(p==0)
                return n;
        }
        while(p*last%t!=0 && last<=9){
            last++;
            n++;
        }
        return n;

    }
};