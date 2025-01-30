//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isSafe(vector<int> &board , int col , int row){
        for(int i=0; i<col; i++){
            int placed = board[i] - 1;
            
            if(placed == row || abs(placed - row) == abs(i - col)){
                return false;
            }
        }
        return true;
    }
    
    void solve(int col , int n , vector<int> &board , vector<vector<int>> &res){
        if(col == n){
            res.push_back(board);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(board , col , i)){
                board[col] = i+1;
                solve(col+1 , n , board , res);
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> res;
        vector<int> board(n , 0);
        
        solve(0 , n , board , res);
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends