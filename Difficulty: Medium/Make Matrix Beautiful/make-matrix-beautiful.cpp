class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(); // Size of the square matrix
        int maxe = INT_MIN; // Initialize max sum to the smallest possible integer
        
        // Step 1: Find the maximum row or column sum (target sum)
        for(int i = 0; i < n; ++i) {
            int rowSum = 0, colSum = 0;
            for(int j = 0; j < n; ++j) {
                rowSum += mat[i][j]; // Sum of current row
                colSum += mat[j][i]; // Sum of current column
            }
            maxe = max({maxe, rowSum, colSum}); // Update maxe to the highest sum
        }
        
        int ans = 0; // Total operations needed
        
        // Step 2: Calculate operations required for each row to reach maxe
        for(int i = 0; i < n; ++i) {
            int rowSum = 0;
            for(int j = 0; j < n; ++j) {
                rowSum += mat[i][j]; // Compute current row sum
            }
            ans += maxe - rowSum; // Add deficit to reach maxe
        }
        
        return ans; // Return total operations
    }
};