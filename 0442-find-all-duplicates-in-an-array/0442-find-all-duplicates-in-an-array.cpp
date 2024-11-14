class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       unordered_map<int, int> hash;
       vector<int> result;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for( auto it: hash){
            if (it.second > 1)
            result.push_back(it.first);
        }
        return result;
        
    }
};