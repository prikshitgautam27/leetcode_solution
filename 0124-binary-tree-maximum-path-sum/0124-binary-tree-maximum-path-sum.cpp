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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        find_max_path_sum(root,maxi);
        return maxi;
    }
    int find_max_path_sum(TreeNode* node,int& maxi ){
if(!node) return 0;
            int leftmax= max(0,find_max_path_sum(node->left,maxi));
            int rightmax=max(0,find_max_path_sum(node->right,maxi));


            maxi=max(maxi,node->val+leftmax+rightmax);


return node->val+max(rightmax,leftmax);


    }
};