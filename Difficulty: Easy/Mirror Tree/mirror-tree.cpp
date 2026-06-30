/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(root == nullptr) {
            return;
        }
        
        mirror(root->left);
        mirror(root->right);
        
        swap(root->left , root->right);
    }
};