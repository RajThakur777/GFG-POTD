class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& matrix) {
        // code here
        
          int rows = matrix.size();
    int cols = matrix[0].size();

    for (int r1 = 0; r1 < rows; ++r1) {
        for (int r2 = r1 + 1; r2 < rows; ++r2) {
            for (int c1 = 0; c1 < cols; ++c1) {
                for (int c2 = c1 + 1; c2 < cols; ++c2) {
                    if (matrix[r1][c1] == 1 && matrix[r1][c2] == 1 &&
                        matrix[r2][c1] == 1 && matrix[r2][c2] == 1) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
    }
};