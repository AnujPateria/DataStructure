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

    // int ans = 0;
    void solve(TreeNode* root, int &tar, long long curr, int &ans){
        if(!root){
            return ;
        }
        curr += root->val;
        if(tar == curr){
            ans += 1;
        }
        solve(root->left, tar , curr, ans);
        solve(root->right, tar , curr, ans);
        // return max(left, right);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        if(root == nullptr) return ans;
        solve(root,targetSum, 0, ans);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
        // return solve(root, targetSum);
    }
};