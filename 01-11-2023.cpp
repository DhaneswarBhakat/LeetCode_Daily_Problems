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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> frequency;
        vector<int> modes;
        int maxFreq = 0;

        inOrderTraversal(root, frequency, maxFreq);

        for (const auto& pair : frequency) {
            if (pair.second == maxFreq) {
                modes.push_back(pair.first);
            }
        }

        return modes;
        
    }

    private:
    void inOrderTraversal(TreeNode* node, unordered_map<int, int>& frequency, int& maxFreq) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left, frequency, maxFreq);

        frequency[node->val]++;
        maxFreq = max(maxFreq, frequency[node->val]);

        inOrderTraversal(node->right, frequency, maxFreq);
    }
};
