class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();

       vector<int> row(n);
       vector<int> col(n);

        for(int i=0; i<n; i++) {
          for(int j=0; j<n; j++) {
            if(mat[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
          }
        } 

        for(int i=0; i<n; i++) {
            if(col[i] == n && row[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};