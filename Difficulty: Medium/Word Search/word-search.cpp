//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool check(vector<vector<char>>& mat , int i , int j , int idx , string &word , vector<vector<bool>> &v){
        if(idx == word.size()){
            return true;
        }
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] || mat[i][j] != word[idx]){
            return false;
        }
        
        v[i][j] = true;
        
        if(check(mat , i , j-1 , idx+1 , word , v) || check(mat , i , j+1 , idx+1 , word , v) || check(mat , i-1 , j , idx+1 , word , v) || check(mat , i+1 , j , idx+1 , word , v)){
            return true;
        }
        v[i][j] = false;
        
        return false;
    }
  
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == word[0]){
                    vector<vector<bool>> v(n , vector<bool>(m , false));
                    if((check(mat , i , j , 0 , word , v))){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends