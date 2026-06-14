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
    // void solve(TreeNode* root, vector<int> &ans){
    //     if(!root) return;
    //     solve(root->left,ans);
    //     ans.push_back(root->val);
    //     solve(root->right,ans);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // solve(root,ans);
        stack<TreeNode*>st;
        TreeNode* c=root;
        while(c || !st.empty()){
            while(c){
                st.push(c);
                c=c->left;
            }
            c=st.top();
            st.pop();
            ans.push_back(c->val);
            c=c->right;
        }
        return ans;
    }
};