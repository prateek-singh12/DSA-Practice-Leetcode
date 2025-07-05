class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num: arr){
            mp[num]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==mp[arr[i]]){
                return arr[i];
            }
        }
        return -1;
    }
};