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

    void solve(TreeNode* node, int &ans, TreeNode* &prev){
        if(node == nullptr) return ;
        solve(node->left, ans, prev);
        if(prev != nullptr){
            ans = min(ans, abs(node->val - prev->val));
        }
        prev = node;
        solve(node->right, ans, prev);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        solve(root, ans, prev);
        return ans;

    }
};