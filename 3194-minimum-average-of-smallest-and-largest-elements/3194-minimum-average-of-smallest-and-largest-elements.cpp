class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        double ans = nums[n-1];       //or  double ans = DBL_MAX;
        for (int i=0, m=n-1; i<n/2; i++, m--) {
            double avg = (nums[i]+nums[m])/2.0; 
            ans = min(ans,avg); // Update ans to the minimum average found
        }
        return ans;
    }
};
