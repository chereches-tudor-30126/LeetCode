/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int validSubtreesCount = 0;
    pair<int, int> dfs(TreeNode* node){
        if (node == nullptr) {
            return {0, 0};
        }
        pair<int, int> leftSubtree = dfs(node->left);
        pair<int, int> rightSubtree = dfs(node->right);

        int currentSum = leftSubtree.first + rightSubtree.first + node->val;
        int currentNodesCount = leftSubtree.second + rightSubtree.second + 1;

        if (node->val == currentSum / currentNodesCount) {
            validSubtreesCount++;
        }

        return {currentSum, currentNodesCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return validSubtreesCount;
    }
};