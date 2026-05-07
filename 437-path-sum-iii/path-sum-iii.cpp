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

    void solve(TreeNode* root, int targetSum, int &count, long long curr){
        if(!root) return ;
        

        curr += root->val;

        if(targetSum == curr){
            count++;
        }

        solve(root->left, targetSum, count, curr);
        solve(root->right, targetSum, count, curr);
        
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(root==nullptr) return 0;
        solve(root, targetSum, count, 0);

        count+=pathSum(root->left, targetSum);
        count+=pathSum(root->right,targetSum);
        return count;
    }
};