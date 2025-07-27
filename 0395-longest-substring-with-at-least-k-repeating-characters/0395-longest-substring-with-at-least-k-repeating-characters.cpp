class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            unordered_map<char, int> freq;
            int start = 0, end = 0;
            int unique = 0;       
            int countAtLeastK = 0;

            while (end < s.size()) {
                // Expand window
                if (unique <= targetUnique) {
                    char c = s[end];
                    if (++freq[c] == 1) unique++;           // new char
                    if (freq[c] == k) countAtLeastK++;      // hits k
                    end++;
                }
                // Shrink window
                else {
                    char c = s[start];
                    if (freq[c] == k) countAtLeastK--;
                    if (--freq[c] == 0) unique--;
                    start++;
                }

                // Valid window
                if (unique == targetUnique && unique == countAtLeastK) {
                    maxLen = max(maxLen, end - start);
                }
            }
        }

        return maxLen;
    }
};
