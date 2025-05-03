//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
    int findNearestFront(int key, vector<int> &primes) {
        if (key <= primes[0]) return primes[0];
        if (key >= primes.back()) return primes.back();
        int l = 0, h = primes.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (primes[mid] >= key) h = mid - 1;
            else l = mid + 1;
        }
        return primes[l];
    }

    int findNearestBack(int key, vector<int> &primes) {
        if (key <= primes[0]) return primes[0];
        if (key >= primes.back()) return primes.back();
        int l = 0, h = primes.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (primes[mid] <= key) l = mid + 1;
            else h = mid - 1;
        }
        return primes[h];
    }

public:
    Node* primeList(Node* head) {
        const int N = 20000;
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false;
        vector<int> primes;
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }
        for (Node* p = head; p; p = p->next) {
            int num = p->val;
            if (num < 2 || !isPrime[num]) {
                int p1 = findNearestFront(num, primes);
                int p2 = findNearestBack(num, primes);
                int d1 = abs(p1 - num), d2 = abs(p2 - num);
                p->val = (d1 < d2 ? p1 : p2);
            }

        }
        return head;
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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends