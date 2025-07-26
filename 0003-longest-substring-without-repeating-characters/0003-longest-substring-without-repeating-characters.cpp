
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int maxLen = 0;

        set<char> st;

        while (j < n) {

            while (st.count(s[j])) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
