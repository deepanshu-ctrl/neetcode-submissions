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
    // vector<vector<int>> ans;
    // void solve(TreeNode* root,int d){
    //     if(!root) return;
    //     if(ans.size()==d) ans.push_back(vector<int>());
    //     ans[d].push_back(root->val);
    //     solve(root->left,d+1);
    //     solve(root->right,d+1);
    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // solve(root,0);
        // return ans;
        if(!root) return {};
        queue<TreeNode*>q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            vector<int>lvl;
            int n=q.size();
            while(n){
                TreeNode* f=q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                lvl.push_back(f->val);
                n--;
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};
