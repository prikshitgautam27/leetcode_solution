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
    int kthSmallest(TreeNode* root, int k) {
      stack  <TreeNode*> st;// 
// recursuvely iterating to the node at left
      TreeNode* cur=root;
      while(cur!= nullptr || !st.empty() ){
            while(cur!=nullptr){
            st.push(cur);
            cur=cur->left;
            }
// processing the node at left;

     cur= st.top();
      st.pop();
      k--;
      if(k==0) return cur->val;

//iterating  the node at right
      cur=cur->right;
      }
    return -1;// it not found
    }

};