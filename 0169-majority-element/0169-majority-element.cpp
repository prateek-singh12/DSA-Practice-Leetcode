class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current=0;
        int count=0;
        for(int num: nums){
            if(count==0){
                current=num;
            }
            if(num==current){count++;}
            else{count--;}
        }
        return current;
    }
};