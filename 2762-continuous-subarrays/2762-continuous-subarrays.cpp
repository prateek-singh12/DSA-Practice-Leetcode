class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int i=0;
        int j=0;
        long long cnt=0;
        while(j<n){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first)>2){
                //shrink window move i 
                mp[nums[i]]-=1;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
          
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};