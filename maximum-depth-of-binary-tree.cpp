#include <algorithm>
using std::max;

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
    int maxDepth(TreeNode* root) {
        return this->maxDepthRecursively(root, 0);
    }
private:

    /* Find max depth on each subtree recursively.
     * Return max between two child subtrees (which is the tree max depth). */

    int maxDepthRecursively(TreeNode* node, int current_depth) {
        if (!node) {
            return current_depth;
        }

        int left_max = this->maxDepthRecursively(node->left, current_depth + 1);
        int right_max = this->maxDepthRecursively(node->right, current_depth + 1);

        return max(left_max, right_max);

    }
};
