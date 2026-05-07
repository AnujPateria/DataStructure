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

    int solve(TreeNode* root, long long curr, int targetSum){
        if(root == nullptr){
            return 0;
        }
        curr += root->val;
        int count = 0;

        if(curr == targetSum){
            // return 1;
            count++;
        }
        count += solve(root->left, curr, targetSum);
        count +=  solve(root->right, curr, targetSum);
        return count;
    }


    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return solve(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        // return ans;
    }
};