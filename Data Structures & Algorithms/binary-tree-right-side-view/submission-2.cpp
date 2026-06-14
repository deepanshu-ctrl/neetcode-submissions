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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int> ans;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            vector<int>lvl;
            int n=q.size();
            int n2=n;
            while(n){
                TreeNode* f=q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                lvl.push_back(f->val);
                n--;
            }
            ans.push_back(lvl[n2-1]);
        }
        return ans;
    }
};
