class Solution {
  public:
  bool isPossible(int mid,vector<int> &arr,vector<int> & cost){
      long long midi = 0;
      long midi_with_one = 0;
      for(int i = 0;i<arr.size();i++){
          midi  += (long long)abs(arr[i]-mid) * cost[i];
          midi_with_one += (long long)abs(arr[i]-(mid+1)) * cost[i];
      }
      return midi<midi_with_one;
  }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int s = 1;
        int e = *max_element(begin(heights),end(heights));
        int mini = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(isPossible(mid,heights,cost)){
                mini  = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        long long ans = 0;
        for(int i=0;i<cost.size();i++){
            ans += (long long)abs(heights[i]-mini) * cost[i];
        }
        return (int)ans;
    }
};

 