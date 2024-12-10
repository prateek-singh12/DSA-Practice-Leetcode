class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>hashset;
        for(int num: arr){
            if(hashset.contains(2*num) || (num%2==0 && hashset.contains(num/2))){
                return true;
            }
            hashset.insert(num);
        }
        return false;
        
    }
};