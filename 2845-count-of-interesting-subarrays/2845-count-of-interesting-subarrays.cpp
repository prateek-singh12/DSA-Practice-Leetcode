class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> countMap;
        countMap[0] = 1; // Prefix sum 0 before start

        long long cnt = 0;
        long long result = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                cnt++;
            }

            int key = ((cnt - k) % modulo + modulo) % modulo;

            if (countMap.count(key)) {
                result += countMap[key];
            }

            countMap[cnt % modulo]++;
        }

        return result;
    }
};
