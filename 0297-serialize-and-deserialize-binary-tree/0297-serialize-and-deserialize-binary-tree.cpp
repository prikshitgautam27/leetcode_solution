class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return ""; // Return empty string for null root
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            if (cur == nullptr) {
                s += "#,";
            } else {
                s += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr; // Correctly handle empty string from serialize

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        
        // Initial root creation
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            // Process Left Child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    cur->left = new TreeNode(stoi(str));
                    q.push(cur->left);
                }
            }

            // Process Right Child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    cur->right = new TreeNode(stoi(str));
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};
