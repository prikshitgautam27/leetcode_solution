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
void helper(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        
        ans.push_back(root->val);      // Root
        helper(root->left, ans);       // Left
        helper(root->right, ans);      // Right
    }
vector<int>preorder;
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        //edge case 
        if(root==nullptr) return preorder;
        helper(root,preorder);
        


return preorder;
    }
};