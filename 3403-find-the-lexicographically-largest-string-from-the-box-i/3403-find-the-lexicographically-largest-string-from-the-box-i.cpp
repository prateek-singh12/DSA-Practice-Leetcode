class Solution {
public:
    string answerString(string word, int num) {
        if (num== 1) {
            return word;
        }
        int n = word.size();
        string res="";
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(n - num + 1, n - i)));
        }
        return res;
    }
};