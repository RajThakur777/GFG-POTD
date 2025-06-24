class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.size();
        
        string res;
        
        for(int i=0; i<n; i++) {
            while(!res.empty() && k > 0 && res.back() < s[i]) {
                res.pop_back();
                k--;
            }
            res += s[i];
        }
        
        while(k) {
            res.pop_back();
            k--;
        }
        return res;
    }
};
