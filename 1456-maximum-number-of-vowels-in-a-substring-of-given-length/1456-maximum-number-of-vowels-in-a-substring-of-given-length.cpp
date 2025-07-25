class Solution {
public:
    bool isVowel(char c) {
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }

    int maxVowels(string s, int k) {
        int n=s.length();
        int curr=0;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            
            if(isVowel(s[j])){
                curr++;
            }
            if(j-i+1 == k){
                ans=max(ans,curr);
                if(isVowel(s[i])) curr--;
                i++;
            }

            j++;
        }
        return ans;
    }
};