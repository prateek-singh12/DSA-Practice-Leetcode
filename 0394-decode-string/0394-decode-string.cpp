class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;       //store repetition numbers
        stack<string> stringStack;   //previous strings
        string curr = "";            
        int k = 0;                  

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                countStack.push(k);
                stringStack.push(curr);

                k = 0;
                curr = "";
            } 
            else if (ch == ']') {
                string decoded = stringStack.top(); stringStack.pop();
                int repeat = countStack.top(); countStack.pop();
                while (repeat--) {
                    decoded += curr;
                }
                curr = decoded;
            }
            else {
                curr += ch;
            }
        }
        return curr;
    }
};
