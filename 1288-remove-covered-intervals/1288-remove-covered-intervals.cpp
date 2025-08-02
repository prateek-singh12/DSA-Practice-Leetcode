class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] > b[1]; // sort by end descending if start is same
            return a[0] < b[0];     // otherwise by start ascending
        });

        int count = 0;
        int maxEnd = 0;

        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;             // not covered, so keep it
                maxEnd = interval[1]; // update max end seen
            }
            // else it is covered → skip
        }

        return count;
    }
};
