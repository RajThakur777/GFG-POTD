// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> t = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        vector<int> ans;
        
        sort(t.rbegin() , t.rend());
        
        for(int i=0; i<t.size(); i++){
            while(N >= t[i]){
                ans.push_back(t[i]);
                N -= t[i];
            }
        }
        
        return ans;
    }
};