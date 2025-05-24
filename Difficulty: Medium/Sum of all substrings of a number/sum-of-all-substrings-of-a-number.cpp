class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.size();
        
        int sum = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string str = s.substr(i , (j - i + 1));
                
                sum += stoi(str);
            }
        }
        return sum;
    }
};