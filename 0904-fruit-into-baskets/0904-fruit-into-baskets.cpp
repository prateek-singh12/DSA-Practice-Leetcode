class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        set<int> st;
        int i=0,j=0;
        int curcount=0;
        int res=0;
        while(j<n){           

            while(st.size()>2){
                curcount--;
                st.erase(fruits[i]);
                i++;
            }

            curcount++;
            st.insert(fruits[j]);
            res=max(res,curcount);

            j++;  
        }
        return res;
    }
};