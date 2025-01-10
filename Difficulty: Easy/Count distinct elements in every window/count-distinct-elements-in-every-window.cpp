//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
        vector<int> ans;
        
        int cnt = 0;
        int i = 0;
        
        map<int , int> mpp;
        for(int j=0; j<n; j++){
            mpp[arr[j]]++;
            
            while((j - i + 1) > k){
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0) mpp.erase(arr[i]);
                i++;
            }
            
            if((j - i + 1) == k){
                ans.push_back(mpp.size());
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends