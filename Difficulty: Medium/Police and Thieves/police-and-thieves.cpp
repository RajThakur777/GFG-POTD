class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        
        int cnt = 0;
        int i = 0;
        int j = 1;
        
        while(i < n && j < n) {
            if(arr[i] == 'P') {
                while(j < n && arr[j] != 'T') {
                    j++;
                }
                if(j < n && ((j - i) <= k)) {
                    arr[i] = 'C';
                    arr[j] = 'C';
                    cnt++;
                    j++;
                }
            }
            else if(arr[i] == 'T'){
                while(j < n && arr[j] != 'P') {
                    j++;
                }
                if(j < n && ((j - i) <= k)) {
                    arr[i] = 'C';
                    arr[j] = 'C';
                    cnt++;
                    j++;
                }
            }
            i++;
        }
        return cnt;
    }
 };