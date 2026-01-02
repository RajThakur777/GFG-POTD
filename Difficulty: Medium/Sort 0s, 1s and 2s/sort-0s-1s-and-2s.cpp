class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int cnt_0 = 0;
        int cnt_1 = 0;
        int cnt_2 = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) {
                cnt_0++;
            }
            else if(arr[i] == 1) {
                cnt_1++;
            }
            else {
                cnt_2++;
            }
        }
        
        int idx = 0;
        
        while(cnt_0--) {
            arr[idx] = 0;
            idx++;
        }
        
        while(cnt_1--) {
            arr[idx] = 1;
            idx++;
        }
        
        while(cnt_2--) {
            arr[idx] = 2;
            idx++;
        }
    }
};