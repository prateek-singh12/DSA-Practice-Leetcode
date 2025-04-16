class Solution {
public:
    static bool compareByEnd(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), compareByEnd);

        int count = 0;
        int end = INT_MIN;

        for (auto interval : intervals) {
            if (interval[0] >= end) {
                end = interval[1];
                count++;
            }
        }

        return intervals.size() - count;
    }
};
