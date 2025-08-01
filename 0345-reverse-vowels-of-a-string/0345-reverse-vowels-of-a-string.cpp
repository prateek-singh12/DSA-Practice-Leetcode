class Solution {
public:
    bool isvowel(char ch){
        char c=tolower(ch);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(!isvowel(s[i])) i++;
            else if(!isvowel(s[j])) j--;
            else {swap(s[i],s[j]);
                i++;j--;}

        }
        return s;
    }
};