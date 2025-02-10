class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto c: s){
            if(isdigit(c)){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{st.push(c);}
        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};