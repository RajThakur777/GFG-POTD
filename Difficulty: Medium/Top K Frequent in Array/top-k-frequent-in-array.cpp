class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        
        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[arr[i]]++;
        }
        
        priority_queue<pair<int , int>> pq;
        for(auto it : mpp) {
            pq.push({it.second , it.first});
        }
        
        vector<int> res;
        
        while(k--) {
            int ele = pq.top().second;
            pq.pop();
            
            res.push_back(ele);
        }
        return res;
    }
};
