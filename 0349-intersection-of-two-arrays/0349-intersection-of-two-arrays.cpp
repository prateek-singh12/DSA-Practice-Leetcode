class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> nums1copy{nums1.begin(), nums1.end()};

    for (int num : nums2)
      if (nums1copy.erase(num))
        ans.push_back(num);

    return ans;
  }
};