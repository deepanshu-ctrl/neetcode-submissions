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
    // int solve(TreeNode* root,int val){
    //     if(!root) return 0;
    //     int ans=(root->val>=val)?1:0;
    //     val=max(val,root->val);
    //     ans+=solve(root->left,val);
    //     ans+=solve(root->right,val);
    //     return ans;
    // }
    int goodNodes(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,-INT_MAX});
        while(!q.empty()){
            auto [n,mv]=q.front();
            q.pop();
            if(n->val>=mv) ans++;
            if(n->left) q.push({n->left,max(n->val,mv)});
            if(n->right) q.push({n->right,max(n->val,mv)});
        }
        return ans;
        // return solve(root,root->val);
    }
};
