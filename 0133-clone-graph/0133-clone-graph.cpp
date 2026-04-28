

class Solution {
public:
    // Hash map to store original node -> cloned node mapping
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If node is already cloned, return the cloned instance
        if (copies.find(node) != copies.end()) {
            return copies[node];
        }

        // Create a deep copy of the current node
        Node* copy = new Node(node->val);
        copies[node] = copy;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};
