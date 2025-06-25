
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -10000000000LL - 1;
        long long right = 10000000000LL + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countLE(mid, nums1, nums2) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

private:
    long long countLE(long long target, vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0;
        for (int a : nums1) {
            if (a == 0) {
                if (target >= 0) {
                    cnt += nums2.size();
                }
            } else if (a > 0) {
                double t = static_cast<double>(target) / a;
                auto it = upper_bound(nums2.begin(), nums2.end(), t);
                cnt += (it - nums2.begin());
            } else {
                double t_val = static_cast<double>(target) / a;
                long long ceil_val = static_cast<long long>(ceil(t_val));
                auto it = lower_bound(nums2.begin(), nums2.end(), ceil_val);
                cnt += (nums2.end() - it);
            }
        }
        return cnt;
    }
};
