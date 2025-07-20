
struct Node {
    map<string, Node*> children; 
    bool deleted = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for (const auto& path : paths) {
            Node* cur = root;
            for (const string& folder : path) {
                if (!cur->children.count(folder))
                    cur->children[folder] = new Node();
                cur = cur->children[folder];
            }
        }
        
        unordered_map<string, vector<Node*>> serial_to_nodes;
        serialize(root, serial_to_nodes);

       for (const auto& [serial, nodes] : serial_to_nodes) {
            if (nodes.size() > 1 && !serial.empty()) { // skip empty serialization (i.e., leaf)
                for (Node* n : nodes)
                    n->deleted = true;
            }
        }

        vector<vector<string>> ans;
        vector<string> curPath;
        dfs(root, curPath, ans);
        return ans;
    }
    
private:
    string serialize(Node* node, unordered_map<string, vector<Node*>>& serial_to_nodes) {
        if (node->children.empty())
            return "";
        string serial = "(";
        for (const auto& [folder, child] : node->children) {
            serial += folder + serialize(child, serial_to_nodes);
        }
        serial += ")";
        serial_to_nodes[serial].push_back(node);
        return serial;
    }
    
    void dfs(Node* node, vector<string>& curPath, vector<vector<string>>& ans) {
        for (const auto& [folder, child] : node->children) {
            if (!child->deleted) {
                curPath.push_back(folder);
                ans.push_back(curPath);
                dfs(child, curPath, ans);
                curPath.pop_back();
            }
        }
    }
};
