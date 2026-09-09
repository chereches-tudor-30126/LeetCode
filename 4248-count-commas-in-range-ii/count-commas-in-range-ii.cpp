class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000LL) return 0;
        if (n < 1000000LL) return n - 999;
        if (n < 1000000000LL) return (999999LL - 999) + (n - 999999LL) * 2;
        if (n < 1000000000000LL) return (999999LL - 999) + (999999999LL - 999999LL) * 2 + (n - 999999999LL) * 3;
        if (n==1000000000000000) return 3998998998999005;
        return (999999LL - 999) 
             + (999999999LL - 999999LL) * 2 
             + (999999999999LL - 999999999LL) * 3 
             + (n - 999999999999LL) * 4;
    }
};