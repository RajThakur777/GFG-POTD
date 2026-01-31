class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        
        vector<pair<int , int>> p;
        
        for(int i=0; i<n; i++) {
            int st = start[i];
            int ed = end[i];
            
            p.push_back({st , +1});
            p.push_back({ed , -1});
        }
        
        sort(p.begin() , p.end());
        
        int v = 0;
        int ans = 0;
        for(int i=0; i<p.size(); i++) {
            v += p[i].second;
            
            ans = max(ans , v);
        }
        return ans;
    }
};
