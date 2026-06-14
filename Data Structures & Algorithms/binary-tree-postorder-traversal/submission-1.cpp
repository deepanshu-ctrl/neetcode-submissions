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
    void solve(TreeNode* root,vector<int> &v){
        if(!root) return;
        solve(root->left,v);
        solve(root->right,v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>st;
        TreeNode* c=root;
        while(c || !st.empty()){
            if(c){
                ans.push_back(c->val);
                st.push(c);
                c=c->right;
            }
            else{
                c=st.top();
                st.pop();
                c=c->left;
            }
        }
        reverse(ans.rbegin(),ans.rend());
        // solve(root,v);
        return ans;
    }
};