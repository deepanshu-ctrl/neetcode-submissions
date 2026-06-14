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
    // bool solve(TreeNode* root,long l,long r){
    //     if(!root) return true;
    //     if(!(l<root->val && r>root->val)) return false;
    //     return solve(root->left,l,root->val) && solve(root->right,root->val,r);
    // }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*,pair<long,long>>>q;
        q.push({root,{LONG_MIN,LONG_MAX}});
        while(!q.empty()){
            auto[node,range]=q.front();
            q.pop();
            long l=range.first, r=range.second;
            if(!(l<node->val && r>node->val)) return false;
            if(node->left) q.push({node->left,{l,node->val}});
            if(node->right) q.push({node->right,{node->val,r}});
        }
        return true;
        // return solve(root,LONG_MIN,LONG_MAX);
    }
};
