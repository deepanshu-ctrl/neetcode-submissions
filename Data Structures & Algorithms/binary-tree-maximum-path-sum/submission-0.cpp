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
    int ans=INT_MIN;
    int maxi(TreeNode* root){
        if(!root) return 0;
        int l=maxi(root->left);
        int r=maxi(root->right);
        int p=root->val+max(l,r);
        return max(0,p);
    }
    void solve(TreeNode* root){
        if(!root) return;
        int l=maxi(root->left);
        int r=maxi(root->right);
        ans=max(ans,root->val+l+r);
        solve(root->left);
        solve(root->right);
        
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
