class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        vector<int> c = arr;
        sort(c.begin() , c.end());
        
        int mini = c[0];
        
        for(int i=0; i<n; i++) {
            if(arr[i] == mini) {
                return i;
            }
        }
        return 0;
    }
};
