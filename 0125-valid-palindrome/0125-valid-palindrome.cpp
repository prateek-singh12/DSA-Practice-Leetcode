class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {//Skip non-alphanumeric characters
                ++l;
                continue;
            }
            if (!isalnum(s[r])) {
                --r;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }
        return true;
    }
};



// class Solution {
//  public:
//   bool isPalindrome(string s) {
//     int l = 0;
//     int r = s.length() - 1;

//     while (l < r) {
//       while (l < r && !isalnum(s[l]))
//         ++l;
//       while (l < r && !isalnum(s[r]))
//         --r;
//       if (tolower(s[l]) != tolower(s[r]))
//         return false;
//       ++l;
//       --r;
//     }

//     return true;
//   }
// };