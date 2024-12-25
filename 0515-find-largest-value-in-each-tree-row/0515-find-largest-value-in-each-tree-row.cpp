class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans; // Check if the root is null
        
        queue<TreeNode*> levelqueue;
        levelqueue.push(root);
        
        while (!levelqueue.empty()) {
            int levelsize = levelqueue.size();
            int maxValue = INT_MIN; // Initialize max value for the level
            
            for (int i = 0; i < levelsize; i++) {
                TreeNode* currentnode = levelqueue.front();
                levelqueue.pop();
                
                // Update the maximum value for the current level
                maxValue = max(maxValue, currentnode->val);
                
                // Push children into the queue if they exist
                if (currentnode->left) levelqueue.push(currentnode->left);
                if (currentnode->right) levelqueue.push(currentnode->right);
            }
            
            ans.push_back(maxValue); // Add the largest value of this level to the result
        }
        
        return ans;
    }
};
