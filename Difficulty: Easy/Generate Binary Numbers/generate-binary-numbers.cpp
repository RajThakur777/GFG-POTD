class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> res;
        
        for(int i=1; i<=n; i++) {
            string ans;
            int ele = i;
            
            while(ele != 0) {
                int num = ele % 2;
                ele /= 2;
                ans += to_string(num);
            }
            
            reverse(ans.begin() , ans.end());
            
            res.push_back(ans);
        }
        return res;
    }
};