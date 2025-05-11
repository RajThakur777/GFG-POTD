//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

#define ll long long
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = (int)arr.size();
        priority_queue<ll> pq;
        for(int i = 0 ; i < n ; i++) {
            ll sum = 0;
            for(int j = i ; j < n ; j++) {
                sum += arr[j];
                pq.push(sum);
            }
        }
        for(int i = 1 ; i < k ; i++) pq.pop();
        return pq.top();
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends