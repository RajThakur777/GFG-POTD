class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin() , b.end());
        
        int n = a.size();
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            int val = a[i];
            
            int idx = upper_bound(b.begin() , b.end() , val) - b.begin();
            
            ans[i] = idx;
        }
        return ans;
    }
};