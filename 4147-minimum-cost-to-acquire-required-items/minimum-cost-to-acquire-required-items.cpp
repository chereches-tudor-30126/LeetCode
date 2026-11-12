class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto calc = [&](long long i) {
            long long c1 = max(0LL, need1 - i);
            long long c2 = max(0LL, need2 - i);
            return i * costBoth + c1 * cost1 + c2 * cost2;
        };
        
        long long candidates[] = {
            0,
            need1,
            need2,
            max((long long)need1, (long long)need2),
            min((long long)need1, (long long)need2)
        };
        
        long long min_val = -1;
        for (long long i : candidates) {
            if (i < 0) continue;
            long long val = calc(i);
            if (min_val == -1 || val < min_val) {
                min_val = val;
            }
        }
        
        return min_val;
    }
};