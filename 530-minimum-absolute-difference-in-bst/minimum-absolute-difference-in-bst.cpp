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
    void mindiff(TreeNode* root , TreeNode* &prev , int &ans){
        if(root==nullptr){
            return ;
        }
        mindiff(root->left , prev , ans);
        if(prev)
        {
            ans = min(ans ,abs( root->val-prev->val));
        }
        prev = root;
        mindiff(root->right , prev , ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = 100000 +  2;
        TreeNode* prev = nullptr;
        mindiff(root , prev , ans); 
        return ans;
       
    }
};