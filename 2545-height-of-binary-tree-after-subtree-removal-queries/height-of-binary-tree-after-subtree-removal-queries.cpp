/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int, int> height;
    unordered_map<int, int> ans;

    // First DFS: compute subtree heights
    int findHeight(TreeNode* root) {
        if (root == nullptr)
            return -1;

        return height[root->val] =
            1 + max(findHeight(root->left), findHeight(root->right));
    }

    // Second DFS: compute answer for every node
    void dfs(TreeNode* root, int depth, int bestAbove) {
        if (root == nullptr)
            return;

        ans[root->val] = bestAbove;

        // Go to left child
        if (root->left) {
            int rightHeight = root->right ? height[root->right->val] : -1;

            dfs(root->left,
                depth + 1,
                max(bestAbove, depth + 1 + rightHeight));
        }

        // Go to right child
        if (root->right) {
            int leftHeight = root->left ? height[root->left->val] : -1;

            dfs(root->right,
                depth + 1,
                max(bestAbove, depth + 1 + leftHeight));
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root);

        dfs(root, 0, 0);

        vector<int> res;

        for (int node : queries)
            res.push_back(ans[node]);

        return res;
    }
};