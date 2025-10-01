class Solution {
  public:
  void fun(set<vector<int>>&st , vector<int>&vec , int i, vector<int>&arr){
      if(i == vec.size()){st.insert(vec);return;}
      for(int j=0;j<vec.size() ; j++){
          if(vec[j] == INT_MIN){
              vec[j] = arr[i];
              fun(st , vec, i+1 , arr);
              vec[j] = INT_MIN;
          }
      }
      
  }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        set<vector<int>>st;
        vector<int>vec(arr) , vc(arr.size() ,  INT_MIN);
        fun(st , vc , 0 , arr);
        vector<vector<int>>ans;        
        for(auto i: st)ans.push_back(i);
        return ans;
    }
};