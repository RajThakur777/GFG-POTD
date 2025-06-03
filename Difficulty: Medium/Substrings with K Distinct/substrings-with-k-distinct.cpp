class Solution {
  public:
  
    int solv(string s , int k) {
        int cnt = 0;
        int i = 0;
        
        int n = s.size();
        
        vector<int> freq(26, 0);
        int dist = 0;
        for(int j=0; j<n; j++){
            freq[s[j] - 'a']++;
            
            if(freq[s[j] - 'a'] == 1) dist++;
            
            while(dist > k){
                freq[s[i] - 'a']--;
                
                if(freq[s[i] - 'a'] == 0){
                    dist--;
                }
                i++;
            }
            
            cnt += (j - i + 1);
        }
        return cnt;
    }
  
    int countSubstr(string& s, int k) {
        // code here.
        int n = s.size();
        
        return solv(s , k) - solv(s , k-1);
    }
};