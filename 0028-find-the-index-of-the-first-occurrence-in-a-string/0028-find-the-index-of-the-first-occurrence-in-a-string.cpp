class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};


// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int h = haystack.size();
//         int n = needle.size();

//         if (n > h) return -1;

//         for (int i = 0; i <= h - n; i++) {
//             if (haystack.substr(i, n) == needle) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


//KMP algo
// class Solution {
// public:
//     vector<int> computeLPS(string needle) {
//         int n = needle.size();
//         vector<int> lps(n, 0);
//         int len = 0; // length of the previous longest prefix suffix

//         for (int i = 1; i < n;) {
//             if (needle[i] == needle[len]) {
//                 len++;
//                 lps[i] = len;
//                 i++;
//             } else {
//                 if (len != 0) {
//                     len = lps[len - 1];
//                 } else {
//                     lps[i] = 0;
//                     i++;
//                 }
//             }
//         }
//         return lps;
//     }

//     int strStr(string haystack, string needle) {
//         if (needle.empty()) return 0;

//         vector<int> lps = computeLPS(needle);
//         int i = 0; // index for haystack
//         int j = 0; // index for needle

//         while (i < haystack.size()) {
//             if (haystack[i] == needle[j]) {
//                 i++;
//                 j++;
//             }

//             if (j == needle.size()) {
//                 return i - j; // Match found
//             } else if (i < haystack.size() && haystack[i] != needle[j]) {
//                 if (j != 0) {
//                     j = lps[j - 1];
//                 } else {
//                     i++;
//                 }
//             }
//         }

//         return -1; // No match
//     }
// };
