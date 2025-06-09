class Solution {
  public:
    bool solve(Node* root, int minVal, int maxVal) {
        if (root == NULL)
            return false;

        // If this is a leaf node
        if (root->left == NULL && root->right == NULL) {
            if (minVal == maxVal)
                return true;
        }

        return solve(root->left, minVal, root->data - 1) ||
               solve(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return solve(root, 1, INT_MAX);
    }
};
