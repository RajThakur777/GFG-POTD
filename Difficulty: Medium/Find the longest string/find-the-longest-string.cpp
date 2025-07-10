class Solution {
  public:
    string longestString(vector<string> &arr) {
        // code here
        int n = arr.size();
        
        unordered_map<string , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[arr[i]]++;
        }
        
        string ans = "";
        
        for(int i=0; i<n; i++) {
            string temp = "";
            for(int j=0; j<arr[i].size(); j++) {
                temp += arr[i][j];
                
                if(mpp.find(temp) == mpp.end()) break;
            }
             if(mpp.find(temp) != mpp.end() && ans.size() < temp.size()) {
                    ans = temp;
                }
                
                if(mpp.find(temp) != mpp.end() && ans.size() == temp.size()) {
                    if(temp < ans) {
                         ans = temp;
                    }
                }
                temp = "";
        }
        return ans;
    }
};