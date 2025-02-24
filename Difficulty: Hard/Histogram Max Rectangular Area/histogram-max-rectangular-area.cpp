//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        vector<int> nsl(n , 0);
        vector<int> nsr(n , 0);
        
        stack<int> st1;
        for(int i=0; i<n; i++){
            while(!st1.empty() && arr[i] <= arr[st1.top()]){
                st1.pop();
            }
            if(st1.empty()){
                nsl[i] = 0;
            }
            else {
                nsl[i] = st1.top() + 1;
            }
            st1.push(i);
        }
        
        stack<int> st2;
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && arr[i] <= arr[st2.top()]){
                st2.pop();
            }
            if(st2.empty()){
                nsr[i] = n-1;
            }
            else {
                nsr[i] = st2.top() - 1;
            }
            st2.push(i);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans , arr[i] * (nsr[i] - nsl[i] + 1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends