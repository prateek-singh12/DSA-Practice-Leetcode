class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26,0);
        for(auto ch: s){
            counter[ch-'a']++;
        }
        for(auto ch: t){
            counter[ch-'a']--;
        }  
        for(auto i: counter){
            if(i!=0){
                return false;
            }
        }
        return true;     
    }
};