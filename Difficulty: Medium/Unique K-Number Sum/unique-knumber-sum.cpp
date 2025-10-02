class Solution {
  public:
  
    void solve(int num , int n , int k , vector<int> temp , vector<vector<int>> &res) {
        if(k == 0 && n == 0) {
            res.push_back(temp);
            return;
        }
        
        for(int i=num; i<=9; i++) {
            temp.push_back(i);
            solve(i+1 , n-i , k-1 , temp , res);
            temp.pop_back();
        }
    }
  
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> res;
        
        vector<int> temp;
        
        solve(1 , n , k , temp , res);
        
        return res;
    }
};