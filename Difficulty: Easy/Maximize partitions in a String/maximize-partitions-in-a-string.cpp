//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size();
        
        vector<int> last(26 , 0);
        for(int i=0; i<n; i++){
            last[s[i] - 'a'] = i;
        }
        
        int st = 0;
        int ed = 0;
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            ed = max(ed , last[s[i] - 'a']);
            
            if(i == ed){
                cnt++;
                st = i+1;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends