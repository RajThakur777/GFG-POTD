class Solution {
  public:
       int solve(int x , vector<int> &a , vector<int> &b , int k) {
        int cnt = 0;

        cnt += upper_bound(a.begin() , a.end() , x) - a.begin();
        cnt += upper_bound(b.begin() , b.end() , x) - b.begin();

        return cnt;
    }
    
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
         int ans = -1;

        int m = a.size();
        int n = b.size();

        int low = min(a[0] , b[0]);
        int high = max(a[m-1] , b[n-1]);

        while(low <= high) {
            int mid = (low + high) / 2;
            
            

            int cntOfEle = solve(mid , a , b , k);
            
            

            if(cntOfEle >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};