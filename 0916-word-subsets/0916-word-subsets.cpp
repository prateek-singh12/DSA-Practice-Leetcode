class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> word2(26, 0);  // store max freq of words2, e.g., words2=['a','o','oo']
        vector<int> temp(26, 0);  // temp is used to calculate the frequency of characters for each word in words2

        // Process words2 to find the maximum frequency for each character
        for (auto str : words2) {
            fill(temp.begin(), temp.end(), 0); // Reset temp for each word in words2
            for (auto ch : str) {
                temp[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                word2[i] = max(temp[i], word2[i]); // Take the maximum frequency for each character
            }
        }
        
        for (auto str1 : words1) {
            vector<int> temp2(26, 0);
            for (auto ch : str1) {
                temp2[ch - 'a']++;
            }
            
            // checking for frequency
            int flag = 0;
            for (int i = 0; i < 26; i++) {
                if (temp2[i] < word2[i]) { // temp2[i] must be at least word2[i]
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                result.push_back(str1);
            }
        }

        return result;
    }
};
