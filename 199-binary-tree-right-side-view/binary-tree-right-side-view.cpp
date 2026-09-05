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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode* > qu;
        qu.push(root);
        qu.push(nullptr);
        TreeNode* prev = nullptr;
        vector<int> ans;
        while(!qu.empty()){
            auto node = qu.front(); qu.pop();
            if(node == nullptr){
                if(prev) {
                    ans.push_back(prev->val);
                }
                if(!qu.empty()){
                    qu.push(nullptr);
                }
            }
            else{
                prev = node;
                if(node->left){
                    qu.push(node->left);
                }
                if(node->right){
                    qu.push(node->right);
                }
            }
        }
        return ans;
    }

};