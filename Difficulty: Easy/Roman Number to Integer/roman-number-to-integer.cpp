class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int n = s.size();
        
        int ans = 0;
        
        map<char , int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        for(int i=0; i<n; i++) {
            char ch1 = s[i];
            char ch2 = s[i+1];
            
            if(mpp[ch1] < mpp[ch2] && (i+1 < n)) {
                ans -= mpp[ch1];
            }
            else {
                ans += mpp[ch1];
            }
        }
        return ans;
    }
};