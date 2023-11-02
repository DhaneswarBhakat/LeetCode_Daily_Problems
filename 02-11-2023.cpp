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
public:
    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int count = 0;
        dfs(root, count);
        
        return count;
    }
        
    private:
    std::pair<int, int> dfs(TreeNode* node, int& count) {
        if (node == nullptr) {
            return {0, 0};
        }

        // Recursively calculate the sum and count of the left subtree.
        auto leftSubtree = dfs(node->left, count);

        // Recursively calculate the sum and count of the right subtree.
        auto rightSubtree = dfs(node->right, count);

        // Calculate the sum and count of the current node's subtree.
        int sum = node->val + leftSubtree.first + rightSubtree.first;
        int subtreeCount = 1 + leftSubtree.second + rightSubtree.second;

        // Calculate the average of the current node's subtree.
        int average = sum / subtreeCount;

        // Check if the node's value is equal to the average.
        if (node->val == average) {
            count++;
        }

        return {sum, subtreeCount};
    }
};
