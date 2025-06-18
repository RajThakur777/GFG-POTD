class Solution {
  public:
  
    bool isPalindrome(string str) {
        int i = 0;
        int j = str.size() - 1;
        
        while(i < j) {
            if(str[i] != str[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string &s , int idx , vector<string> &curr , vector<vector<string>> &ans) {
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            string str = s.substr(idx , i - idx + 1);
            if(isPalindrome(str)) {
                curr.push_back(str);
                solve(s , i+1 , curr , ans);
                curr.pop_back();
            }
        }
    }
  
    vector<vector<string>> palinParts(string &s) {
        // code here
        int n = s.size();
        
        vector<string> curr;
        
        vector<vector<string>> ans;
        
        solve(s , 0 , curr , ans);
        
        return ans;
    }
};