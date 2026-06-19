class Solution {
  public:
    int m;
    int n;

    vector<string> ans;

    void solve(int i , int j , vector<vector<int> > &grid , int m , int n , string str) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        
        if(i == m-1 && j == n-1) {
           ans.push_back(str);
           return;
        }

        grid[i][j] = 0;

        solve(i+1 , j , grid , m , n , str + 'D');
        solve(i-1 , j , grid , m , n , str + 'U');
        solve(i , j+1 , grid , m , n , str + 'R');
        solve(i , j-1 , grid , m , n , str + 'L');

        grid[i][j] = 1;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        m = maze.size();
        n = maze[0].size();

        string str;

        solve(0 , 0 , maze , m , n , str);
        
        sort(ans.begin() , ans.end());

        return ans;
    }
};