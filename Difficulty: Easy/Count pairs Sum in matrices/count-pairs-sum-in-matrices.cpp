class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        set<int> s;
         int counter=0;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 s.insert(mat2[i][j]);
             }
         }
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 int res=x-mat1[i][j];
                 if(s.find(res)!=s.end())
                 {
                     counter++;
                 }
             }
         }
         return counter;
    }
};