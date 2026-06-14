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
        if(mpp.find(root)!=mpp.end()) return mpp[root];
        int ans=root->val;
        if(root->left) ans+=solve(root->left->left)+solve(root->left->right);
        if(root->right) ans+=solve(root->right->left)+solve(root->right->right);
        ans=max(ans,solve(root->left)+solve(root->right));
        return mpp[root]=ans;
    }
    int rob(TreeNode* root) {
        mpp[nullptr]=0;
        return solve(root);
        // if(!root) return 0;
        // int ans=root->val;
        // if(root->left){
        //     ans+=rob(root->left->left)+rob(root->left->right);
        // }
        // if(root->right){
        //     ans+=rob(root->right->right)+rob(root->right->left);
        // }
        // ans=max(ans,rob(root->left)+rob(root->right));
        // return ans;
    }
};