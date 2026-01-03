/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        if(root == nullptr) return root;
        
        Node* temp = root;
        
        vector<int> ans;
        
        while(temp != nullptr) {
            ans.push_back(temp->data);
            
            Node* t = temp->bottom;
            
            while(t != nullptr) {
                ans.push_back(t->data);
                t = t->bottom;
            }
            temp = temp->next;
        }
        
        sort(ans.begin() , ans.end());
        
        Node* dummy = new Node(-1);
        Node* p = dummy;
        int i = 0;
        while(i < ans.size()) {
            p->bottom = new Node(ans[i]);
            p = p->bottom;
            i++;
        }
        return dummy->bottom;
    }
};