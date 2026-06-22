class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // code here
             sort(nums1.rbegin() , nums1.rend());
      sort(nums2.rbegin() , nums2.rend());

      int n = nums1.size();

      priority_queue<pair<int , pair<int , int>>> pq;

      set<pair<int , int>> st;

      pq.push({nums1[0] + nums2[0] , {0 , 0}});
      st.insert({0 , 0});

      int cnt = k;

      vector<int> ans;

      while(cnt != 0 && !pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int sum = it.first;
        int i = it.second.first;
        int j = it.second.second;

        ans.push_back(sum);
        
        cnt--;

        if(i + 1 < n && st.find({i + 1 , j}) == st.end()) {
            pq.push({nums1[i+1] + nums2[j] , {i+1 , j}});
            st.insert({i+1 , j});
        }

        if(j + 1 < n && st.find({i , j + 1}) == st.end()) {
            pq.push({nums1[i] + nums2[j + 1] , {i , j + 1}});
            st.insert({i , j + 1});
        }
      }

      return ans;
    }
};