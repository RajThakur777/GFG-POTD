class Solution {
  public:
    bool check(vector<int>& citations, int n, int mid){
        int cnt=0;
        for(int i=0;i<n;i++){ // O(N)
            if(citations[i]>=mid) cnt++;
        }
        return cnt>=mid;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int lo=0, hi=n;
        while(lo<=hi){   // O(logN)
            int mid=(lo+hi)/2;
            if(check(citations, n, mid)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};