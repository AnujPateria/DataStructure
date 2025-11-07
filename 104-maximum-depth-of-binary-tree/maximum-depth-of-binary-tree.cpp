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


    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int ans = 0;
        ans = max(ans ,1+ maxDepth(root->left));
        ans = max(ans ,1+ maxDepth(root->right));
        return ans;
        
    }
};