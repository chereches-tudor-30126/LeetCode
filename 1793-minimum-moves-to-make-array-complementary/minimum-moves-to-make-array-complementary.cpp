class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {  
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        
        int delta[200005] = {0}; 
        
        int half = n / 2;
        int* p_nums = nums.data(); 
        
        for (int i = 0; i < half; ++i) {
            int a = p_nums[i];
            int b = p_nums[n - 1 - i];

            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            
            delta[1 + a] -= 1;
            delta[a + b] -= 1;
            delta[a + b + 1] += 1;
            delta[limit + b + 1] += 1;
        }
        
        int current_moves = n;
        int min_moves = n;
        int max_target = 2 * limit;
        
        for (int i = 2; i <= max_target; ++i) {
            current_moves += delta[i];
            if (current_moves < min_moves) {
                min_moves = current_moves;
            }
        }
        
        return min_moves;
    }
};