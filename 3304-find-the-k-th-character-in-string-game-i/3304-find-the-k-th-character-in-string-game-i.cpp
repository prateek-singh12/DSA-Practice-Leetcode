class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        while (word.length() < k) {
            string temp = "";
            for (char ch : word) {
                // (z -> a)
                temp += (ch == 'z') ? 'a' : (ch + 1);
            }
            word += temp;
        }
        
        return word[k - 1];  // 0-indexed
    }
};
