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
    int ans = 0;
    int solve(TreeNode* node){
        if(node==nullptr) return 0;
        int left = solve(node->left);
        int right = solve(node->right);
        int currMax = max({node->val , left, right});
        if(node->val == currMax) ans++;
        return currMax;

    }

    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;

    }
};