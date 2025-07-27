class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        vector<pair<int , int>> v;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    v.push_back({i , j});
                }
            }
        }
        
        for(auto it : v) {
            int u = it.first;
            int v = it.second;
            
            for(int i=0; i<n; i++) {
                mat[u][i] = 0;
            }
            
            for(int i=0; i<m; i++) {
                mat[i][v] = 0;
            }
        }
    }
};