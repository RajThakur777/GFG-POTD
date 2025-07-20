class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int sz = arr.size();
        
        long long num = 1;
        num *= 9;
        
        for(int i=1; i<n; i++) {
            num *= 10;
        }
        
        set<int> st;
        for(int i=0; i<sz; i++) {
            st.insert(arr[i]);
        }
        
        long long rem = 10 - st.size();
        
        
        bool flag = false;
        for(auto it : st) {
            if(st.find(0) != st.end()) {
                flag = true;
                break;
            }
        }
        
        if(!flag) {
             long long res = 1;
        res *= (rem - 1);
        
        for(int i=1; i<n; i++) {
            res *= rem;
        }
        
        return (num - res);
        }
        
        long long res = 1;
        
        for(int i=0; i<n; i++) {
            res *= rem;
        }
        return (num - res);
    }
};
