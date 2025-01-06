class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result;
        vector<int> positions;
        int n = boxes.size();
        
        // Collect indices where boxes contain '1'
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                positions.push_back(i);
            }
        }

        // Calculate the total number of operations for each box
        for (int i = 0; i < n; i++) {
            int totalOperations = 0;
            for (int pos : positions) {
                totalOperations += abs(i - pos);
            }
            result.push_back(totalOperations);
        }

        return result;
    }
};
