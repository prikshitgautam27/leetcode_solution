/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        if(root==nullptr || p==root || q==root) return root;

        TreeNode* leftres=lowestCommonAncestor( root->left,  p,  q);
        TreeNode* rightres=lowestCommonAncestor( root->right,  p,  q);

    if(leftres !=nullptr  && rightres!=nullptr) return root;

    if(leftres==nullptr ) return rightres;
    else{
        return leftres;
    }

    }
};