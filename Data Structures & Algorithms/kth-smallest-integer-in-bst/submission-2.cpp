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
    // void solve(TreeNode* root,vector<int> &v){
    //     if(!root) return;
    //     solve(root->left,v);
    //     v.push_back(root->val);
    //     solve(root->right,v);
    // }
    int cnt=0,ans=0;
    void solve(TreeNode* root, int k){
        if(!root) return;
        solve(root->left,k);
        cnt++;
        if(cnt==k){ans=root->val; return;}
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* c=q.front(); q.pop();
            pq.push(c->val);
            if(c->left) q.push(c->left);
            if(c->right) q.push(c->right);
        }
        while(--k) pq.pop();
        return pq.top();
        // solve(root,k);;
        // return ans;
        // vector<int>v;
        // solve(root,v);
        // return v[k-1];
    }
};
