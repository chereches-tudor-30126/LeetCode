class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
       
        vector<int> delta(2 * limit + 2, 0);
        
        for (int i = 0; i < n / 2; ++i) {
            int A = min(nums[i], nums[n - 1 - i]);
            int B = max(nums[i], nums[n - 1 - i]);
            
           
            delta[1 + A] -= 1;             
            delta[A + B] -= 1;            
            delta[A + B + 1] += 1;       
            delta[B + limit + 1] += 1;     
        }
        
      
        int current_moves = n; 
        int min_moves = n;
        
       
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += delta[i];
            min_moves = min(min_moves, current_moves);
        }
        
        return min_moves;
    }
};