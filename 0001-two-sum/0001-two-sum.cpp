class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
       //sort(nums.begin(),nums.end()); //sorting the nums array in-place, but after sorting, you lose the original indices of the elements.
        vector<pair<int,int>> clone;
        for(int i=0;i<nums.size();i++){
            clone.push_back({nums[i],i});
        }
       sort(clone.begin(),clone.end());
       int l=0;
       int r=nums.size()-1;
       while(l<=r){
            if(clone[l].first+clone[r].first==target){
                    res.push_back(clone[l].second);
                    res.push_back(clone[r].second);
                    return res;
                } 
            else if(clone[l].first+clone[r].first>target){r--;}
            else{l++;}
       }
       return res;
    }
};


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> numMap;
//         vector<int> ans;
        
//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];
            
//             //if complement exists in the map
//             if (numMap.find(complement) != numMap.end()) {
//                 ans.push_back(numMap[complement]);
//                 ans.push_back(i);
//                 return ans;
//             }           
//             numMap[nums[i]] = i;
//         }
        
//         return ans;
//     }
// };

