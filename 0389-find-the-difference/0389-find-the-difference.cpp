class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) return t[i];
        }
        return t.back();  // Last char is extra
    }
};