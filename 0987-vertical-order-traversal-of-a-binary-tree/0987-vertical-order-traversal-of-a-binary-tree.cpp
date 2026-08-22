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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<tuple<TreeNode*, int ,int>>q;// col -> [(row,val)]
        map<int,vector<pair<int,int>>>mp;// node,row,col
        q.push({root,0,0});

        while(!q.empty()){
            auto [node,row,col]=q.front();
            q.pop();

            mp[col].push_back({row,node->val});

            if(node->left) q.push({node->left,row+1,col-1});
            if(node->right) q.push({node->right,row+1,col+1});

        }
        vector<vector<int>>res;
        for(auto &p:mp){
            auto vec=p.second;// put (row,val) to vec
            sort(vec.begin(),vec.end());// sort the vector by row then by val
            vector<int>colval;
            for(auto x:vec) {
                colval.push_back(x.second);
            }
            res.push_back(colval);
        }
return res;
    }
};