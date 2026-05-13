class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {  
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int delta[200005] = {0}; 
        int n = nums.size();
        
        const int* left = nums.data();
        const int* right = left + n - 1;
        
        while (left < right) {
            int a = *left++;
            int b = *right--;
            
            if (a > b) {
                int t = a; 
                a = b; 
                b = t;
            }
            
            delta[a + 1]--;
            delta[a + b]--;
            delta[a + b + 1]++;
            delta[b + limit + 1]++;
        }
        
        int current = n;
        int min_m = n;
        int max_target = (limit << 1) + 1;
        
        const int* d = delta + 2;
        const int* d_end = delta + max_target;
        
        while (d != d_end) {
            current += *d++;
            if (current < min_m) {
                min_m = current;
            }
        }
        
        return min_m;
    }
};