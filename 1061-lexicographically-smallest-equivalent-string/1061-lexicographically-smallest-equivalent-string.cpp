class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char map[26];
        for (int i = 0; i < 26; i++)
            map[i] = i + 'a'; 

        for (int i = 0; i < s1.length(); i++) {
            char a = s1[i];
            char b = s2[i];
            char minChar = min(map[a - 'a'], map[b - 'a']);
            char maxChar = max(map[a - 'a'], map[b - 'a']);
            for (int j = 0; j < 26; j++) {
                if (map[j] == maxChar) {
                    map[j] = minChar;
                }
            }
        }

        string result;
        for (char c : baseStr) {
            result += map[c - 'a'];
        }

        return result;
    }
};
