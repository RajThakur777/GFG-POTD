class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        int n = s.size();
        
        map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }
        
        priority_queue<int> pq;
        for(auto it : mpp) {
            pq.push(it.second);
        }
        
        while(k-- && !pq.empty()) {
            int val = pq.top();
            pq.pop();
            
            if(val > 1) {
                pq.push(val - 1);
            }
        }
        
        int ans = 0;
        while(!pq.empty()) {
            ans += (pq.top() * pq.top());
            pq.pop();
        }
        return ans;
    }
};