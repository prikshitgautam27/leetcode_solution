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
bool checksym(TreeNode* l,TreeNode* r){
    if(l==nullptr && r==nullptr){
        return true;
    }
    if(l==nullptr || r==nullptr){
        return false;
    }
    if(l->val !=r->val){
        return false;

    }
    if(checksym(l->left,r->right)==false) return false;
    if(checksym(l->right,r->left)==false) return false;

    return true;
}
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        if(checksym(root->left,root->right)==false) return false;

        return true;
    }

};