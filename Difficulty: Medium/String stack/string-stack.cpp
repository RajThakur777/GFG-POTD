class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int i = tar.size() - 1;
        int j = pat.size() - 1;

        if (pat.size() < tar.size()) return false;

        while (j >= 0 && i >= 0) {
            if (tar[i] == pat[j]) {
                i--;
                j--;
            } else {
                j-=2;
            }
            if(j<=-1 && i<0) return true;
            
        }
        return i<0?true:false;
    }
};

