struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    /* Inverting a binary tree means swapping children on all tree levels.
     * This can be accomplished in a bottom-up manner using recursion. */
    TreeNode* invertTree(TreeNode* root) {
       this->invertTreeRecursively(root);

        return root;
    }
private:
    void invertTreeRecursively(TreeNode* root) {

        // End-case: a leaf has been reached
        if (!root) return;

        // Invert tree recursively on both sides
        this->invertTreeRecursively(root->left);
        this->invertTreeRecursively(root->right);

        // Swap between children of root
        TreeNode* temp = root->left;

        root->left = root->right;
        root->right = temp;
    }
};
