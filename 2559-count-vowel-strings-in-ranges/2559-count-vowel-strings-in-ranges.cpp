class Solution {
public:
    bool isVowel(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = words.size();
        vector<int> result;
        vector<int> cumulative(n); // Cumulative sum array
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length() - 1])) {
                sum++;
            }
            cumulative[i] = sum; // //Cumultive sum array for strings starting and edning with vowel ex for Example1: cumulative=[1,1+0,2,3,4]
        }
        
        for (auto query : queries) {
            int l = query[0];
            int r = query[1];
            if (l == 0) { // Handle case where l == 0 otherwise l-1
                result.push_back(cumulative[r]);
            } else {
                result.push_back(cumulative[r] - cumulative[l - 1]);
            }
        }
        
        return result;
    }
};
