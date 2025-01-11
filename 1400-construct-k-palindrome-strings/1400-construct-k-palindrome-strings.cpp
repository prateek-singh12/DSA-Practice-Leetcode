class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k){return true;} //example 3
        if(n<k){return false;}
        vector <int> ch(26,0);
        for(auto c : s){
            ch[c-'a']++;
        }
        int odd_occurrence=0;
        for(int i=0;i<26;i++){
            if(ch[i]%2 != 0){
                odd_occurrence++;
            }
        }
        if(odd_occurrence <= k){
            return true;
        }
        return false;
    }
};