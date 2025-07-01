class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.size();
        
        int ans = 0;
        
        map<char , int> mpp;
        
        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[s[j]]++;
            
            while((j - i + 1) > k) {
                mpp[s[i]]--;
                
                if(mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            
            if(mpp.size() == (k - 1) && (j - i + 1) == k) {
                ans++;
            }
        }
        return ans;
    }
};