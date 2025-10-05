class Solution {
  public:
    int n;
    
    void solve(int i , int j , vector<vector<int>> &maze , string temp , vector<string> &ans) {
        if(i == n-1 && j == n-1) {
            ans.push_back(temp);
            return;
        }
        
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0) return;
        
        maze[i][j] = 0;
        
        solve(i+1 , j , maze , temp+'D' , ans);
        solve(i-1 , j , maze , temp+'U' , ans);
        solve(i , j+1 , maze , temp+'R' , ans);
        solve(i , j-1 , maze , temp+'L' , ans);
        
        maze[i][j] = 1;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze[0].size();
        
        vector<string> ans;
        
        string temp;
        
        solve(0 , 0 , maze , temp , ans);
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};