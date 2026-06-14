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
    int solve(TreeNode* root, int mv){
        if(!root) return 0;
        int ans=(root->val>=mv)?1:0;
        mv=max(mv,root->val);
        ans+=solve(root->left,mv);
        ans+=solve(root->right,mv);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        // int ans=0;
        // queue<pair<TreeNode*, int>> q;
        // q.push({root,-INT_MAX});
        // while(!q.empty()){
        //     auto [node,mv]=q.front();
        //     q.pop();
        //     if(node->val >= mv) ans++;
        //     if(node->left) q.push({node->left,max(node->val,mv)});
        //     if(node->right) q.push({node->right,max(mv,node->val)});
        // }
        // return ans;
        return solve(root,root->val);
    }
};
