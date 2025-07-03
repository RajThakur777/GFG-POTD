class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        
        map<char , int> mpp;
        
        int ans = INT_MIN;
        
        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[s[j]]++;
            
            while(mpp.size() > k) {
                mpp[s[i]]--;
                
                if(mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            
            if(mpp.size() == k) {
                ans = max(ans , (j - i + 1));
            }
        }
        
        if(ans == INT_MIN) return -1;
        return ans;
    }
};