class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto num: nums){
            if((num>=10 && num<=99) || (num>=1000 && num<=9999) || (num==100000) )
                ans++;
        }
        return ans;
    }
};