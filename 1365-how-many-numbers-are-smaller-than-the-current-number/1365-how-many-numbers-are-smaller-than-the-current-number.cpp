class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted_num=nums;
        sort(sorted_num.begin(),sorted_num.end());
        unordered_map<int,int> mp;
        for(int i=0; i<sorted_num.size(); i++){
            if(mp.find(sorted_num[i])==mp.end()){
                mp[sorted_num[i]]=i;
            }
        }
        vector<int> res;
        for(int num:nums){
            res.push_back(mp[num]);
        }
        return res;
    }
};