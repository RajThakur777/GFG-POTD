//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverse(Node* head) {
        Node* temp = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        while(temp != nullptr) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        return prev;
    }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        
        if(num1 == nullptr) return num2;
        if(num2 == nullptr) return num1;
        
        Node* first = reverse(num1);
        Node* second = reverse(num2);
        
        Node* temp1 = first;
        Node* temp2 = second;
        
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        int carry = 0;
        
        while(temp1 != nullptr || temp2 != nullptr || carry > 0) {
            int sum = ((temp1) ? (temp1->data) : 0) + ((temp2) ? (temp2->data) : 0) + carry;
            
            Node* newNode = new Node(sum % 10);
            curr->next = newNode;
            curr = curr->next;
            carry = sum / 10;
            
            if(temp1 != nullptr) temp1 = temp1->next;
            if(temp2 != nullptr) temp2 = temp2->next;
        }
        
        // Reverse the result to get the correct order.
        dummy = dummy->next;
        Node* reversedResult = reverse(dummy);
        
        // To handle leading zeros, check and remove them.
        Node* result = reversedResult;
        while(result != nullptr && result->data == 0) {
            result = result->next;
        }
        
        return result ? result : new Node(0); // if result is null, return node with 0.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends