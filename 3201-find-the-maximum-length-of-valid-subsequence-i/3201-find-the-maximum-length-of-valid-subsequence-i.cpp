class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;
        int alter=1;
        for(auto num:nums){
            if(num%2==0) even++;
            else odd++;
        }
        int previousparity=nums[0]%2;
        for(int i=1;i<nums.size();i++){
            int currentparity=nums[i]%2;
            if(currentparity!=previousparity) alter++;
            previousparity=currentparity;
        }

        return max({even,odd,alter});
    }
};