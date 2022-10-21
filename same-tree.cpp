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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // In case a leaf has been reached, both nodes need to be empty
        if (!p || !q)
            return p == q;

        // Test for a value mismatch
        if (p->val != q->val)
            return false;

        // Recursively compare both subtrees for equalities
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
