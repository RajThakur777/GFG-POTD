class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> arr = {1 , 2 , 5 , 10};
        
        int cnt = 0;
        
        sort(arr.begin() , arr.end());
        
        int ele = n;
        
        for(int i=arr.size()-1; i>=0; i--) {
            int val = (ele / arr[i]);
            int value = (val * arr[i]);
            
            ele -= value;
            cnt += val;
            
            if(ele == 0) {
                break;
            }
        }
        return cnt;
    }
};