class Solution {
 public:
  long long findScore(vector<int>& nums) {
    long ans = 0;
    set<pair<int, int>> hash;
    vector<bool> seen(nums.size());

    for (int i = 0; i < nums.size(); ++i)
      hash.insert({nums[i], i});

    for (auto [num, i] : hash) {
      if (seen[i])
        continue;
      else{ //not yet marked therfore mark it and add to result
          if (i > 0)
            seen[i - 1] = true;
          if (i + 1 < nums.size())
            seen[i + 1] = true;
          seen[i] = true;
          ans += num;
        }
    }

    return ans;
  }
};