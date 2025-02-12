class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int result = -1;
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int &num : nums) {
            int digit_sum = digitSum(num);
            vec.push_back({digit_sum, num});
        }

        sort(begin(vec), end(vec));  //sort wrt digit_sum

        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].first == vec[i-1].first) {
                result = max(result, vec[i].second + vec[i - 1].second);
            }
        }
        return result;
    }
};