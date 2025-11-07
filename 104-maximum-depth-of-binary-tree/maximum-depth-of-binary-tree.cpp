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
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
           
            int sz = qu.size();

            for(int i = 0 ; i < sz ; i++){
                TreeNode* front = qu.front();
                qu.pop();
                if(front->left){
                    qu.push(front->left);
                }
                if(front->right){
                    qu.push(front->right);
                }
            }

            ans++;
        }
        return ans;

    }
};