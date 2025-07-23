class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        long long ans=0,mod=1e9+7,n=arr.size();
        for(long long i=0;i<arr.size();i++){
            ans+=arr[i]*(i+1)*(n-i);
        }
        return ans;
    }
};