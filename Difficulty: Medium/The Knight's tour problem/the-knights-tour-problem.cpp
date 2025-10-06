class Solution {
  public:
  
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool solve(int i , int j , vector<vector<int>> &grid , int move , int n) {
        if(move == (n*n)) return true;
        
        for(int d=0; d<8; d++) {
            int i_ = i + dx[d];
            int j_ = j + dy[d];
            
            if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] == -1) {
                grid[i_][j_] = move;
                if(solve(i_ , j_ , grid , move+1 , n) == true) {
                    return true;
                }
                grid[i_][j_] = -1;
            }
        }
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> grid(n , vector<int>(n , -1));
        
        grid[0][0] = 0;
        
        bool flag = solve(0 , 0 , grid , 1 , n);
        
        if(flag == true) {
            return grid;
        }
        else {
            return {{-1}};   
        }
    }
};