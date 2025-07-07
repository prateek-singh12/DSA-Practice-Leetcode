class Solution {
public:
    static bool compareByEnd(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; //ascending order of ending time
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), compareByEnd);

        int count = 0;
        int end = INT_MIN;
        
        for (auto interval : intervals) {
            if (interval[0] >= end) {
                end = interval[1];
                count++;//feasuble or correct events //return total -count
            }
        }

        return intervals.size() - count;
    }
};
