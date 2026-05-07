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

    void solve(TreeNode* root, int curr, int targetSum, vector<vector<int>> & res, vector<int> &arr){
        if(root==nullptr){ 
            return ;
        }
        // vector<int> arr;
        arr.push_back(root->val);
        curr += root->val;

        if(curr == targetSum && root->left == nullptr && root->right == nullptr){
            res.push_back(arr);
        }

        solve(root->left, curr, targetSum, res, arr);
        solve(root->right, curr, targetSum, res, arr);
        arr.pop_back();



    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> res;
        vector<int> arr;
        //condition : root->last == null 
        solve(root, 0, targetSum, res, arr);
        return res;
    }
};