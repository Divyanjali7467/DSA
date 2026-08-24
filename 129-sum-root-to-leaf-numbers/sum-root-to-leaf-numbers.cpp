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
    void dfs(TreeNode* root, int cn, int &sum){
        if(root==NULL)
        return;
        cn=cn*10+(root->val);
        if(root->left==NULL && root->right==NULL){
            sum+=cn;
        }
        dfs(root->left,cn,sum);
        dfs(root->right,cn,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        dfs(root,0,sum);
        return sum;
        
    }
};