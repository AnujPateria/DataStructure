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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(root==nullptr){
            // ans.push_back(root->data);
            return ans;
        }
        // ans.push_back(root->data);

        qu.push(root);
        
        // ans.push_back()
        while(!qu.empty()){
            
            // auto fr = qu.front();
            int sz = qu.size();
            vector<int> ch;
            // qu.pop();

            for(int i = 0 ; i < sz ; i++){
                TreeNode* st = qu.front();
                ch.push_back(st->val);
                qu.pop();
                if(st->left){
                    qu.push(st->left);
                }
                if(st->right){
                    qu.push(st->right);
                }
            }
            ans.push_back(ch);
        
        }
        return ans;

    }
};