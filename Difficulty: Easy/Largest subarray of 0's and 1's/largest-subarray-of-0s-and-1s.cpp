//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        int sum = 0;
        int maxi = 0;
        
        map<int , int> mpp;
        mpp[0] = -1;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi , i - mpp[sum]);
            }
            
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends