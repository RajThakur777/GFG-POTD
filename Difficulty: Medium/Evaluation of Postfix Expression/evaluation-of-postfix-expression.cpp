//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        int n = arr.size();
        
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(arr[i] == "+" || arr[i] == "*" || arr[i] == "-" || arr[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if(arr[i] == "+"){
                    st.push(a+b);
                }
                else if(arr[i] == "-"){
                    st.push(b-a);
                }
                else if(arr[i] == "*"){
                    st.push(b*a);
                }
                else {
                    st.push(b/a);
                }
            }
            else {
                int num = stoi(arr[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends