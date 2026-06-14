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
    unordered_map<TreeNode*,int>mpp;
    int solve(TreeNode* root){
        if(!root) return 0;
        if(mpp.count(root)) return mpp[root];
        int tk=root->val;
        if(root->left)
            tk+=solve(root->left->left)+solve(root->left->right);
        if(root->right)
            tk+=solve(root->right->left)+solve(root->right->right);
        int nt=solve(root->left)+solve(root->right);
        return mpp[root]=max(tk,nt);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};