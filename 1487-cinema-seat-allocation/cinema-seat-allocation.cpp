class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> blocked;
        for (const auto& seat : reservedSeats){
            int row=seat[0];
            int col=seat[1];
            if (col>=2 && col<=5) blocked[row] |= 1; 
            if (col>=6 && col<=9) blocked[row] |= 2; 
            if (col>=4 && col<=7) blocked[row] |= 4;
        }
        int ans=(n-blocked.size())*2;
        for (auto const& [row, mask] : blocked){
            if ((mask & 1) == 0 && (mask & 2) == 0){
                ans+=2;
            } 
            else if((mask & 1) == 0 || (mask & 2) == 0 || (mask & 4) == 0){
                ans+=1;
            }
        }
        return ans;
    }
    
};