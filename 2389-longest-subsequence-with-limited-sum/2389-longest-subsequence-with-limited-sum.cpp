class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        sort(nums.begin(), nums.end()); 
        for (int i = 0; i < queries.size(); i++) {
            answer.push_back(maxSubsequenceSize(nums, queries[i]));
        }
        return answer;
    }
    
    int maxSubsequenceSize(vector<int>& arr, int limit) { 
        int sum = 0;
        int count = 0;         
        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] > limit) break; 
            sum += arr[i];
            count++;
        }
        return count;
    }
};
