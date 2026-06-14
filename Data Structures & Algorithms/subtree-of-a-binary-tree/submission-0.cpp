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
    bool same(TreeNode* root, TreeNode* sb){
        if(!root && !sb) return true;
        if(root && sb && root->val==sb->val){
            return same(root->left,sb->left) && same(root->right,sb->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* sb) {
        if(!sb) return true;
        if(!root) return false;
        if(same(root,sb)) return true;
        return isSubtree(root->left,sb)||isSubtree(root->right,sb);
    }
};
