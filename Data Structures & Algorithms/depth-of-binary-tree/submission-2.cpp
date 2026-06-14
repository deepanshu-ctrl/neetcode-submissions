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
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        return 1+max(l,r);
    }
    int maxDepth(TreeNode* root) {
        // return solve(root);
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        int ans=0;
        while(!st.empty()){
            pair<TreeNode*,int> c=st.top();
            st.pop();
            TreeNode* node=c.first;
            int d=c.second;
            if(node){
                ans=max(ans,d);
                st.push({node->left,d+1});
                st.push({node->right,d+1});
            }
        }
        return ans;
    }
};
