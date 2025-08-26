class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        
        int i = 0;
        int j = 0;
        while(i < m && j < n) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        
        return (i == m);
    }
};