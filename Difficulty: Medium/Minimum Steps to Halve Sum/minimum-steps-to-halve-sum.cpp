class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int n = arr.size();
        
           priority_queue<double>p;
        double sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=(double)arr[i];
            p.push(double(arr[i]));
        }
       double half=(double)sum/2;
       int oper=0;
       while(half<sum)
       {
           double ele=p.top();
           p.pop();
           ele=ele/2;
           sum-=ele;
           oper++; 
           p.push(ele);
       }
       return oper;
    }
};