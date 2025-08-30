class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n =  mat.size();
        for(int i =0 ;i<n;i++){
            int count = 0;
            int count1 = 0;
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0)count++;
                if(mat[j][i] == 1)count1++;
                
            }
            if(count == n-1 && count1 == n)return i;
        }
        return -1;
    }
};

