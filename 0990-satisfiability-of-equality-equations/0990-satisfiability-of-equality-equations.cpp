class Solution {
public:
    int find(int x, vector<int> &parent) {
        if (parent[x] == x)
            return x;  
        return find(parent[x],parent);
    }

    void union_xy(int x, int y,vector<int> &parent) {
        int px=find(x,parent);
        int py=find(y,parent);
        if(py!=px){
            parent[px]=py;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        //"==" equations
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                union_xy(a, b, parent);
            }
        }

        // "!=" equations
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                if (find(a,parent) == find(b,parent))  // contradiction
                    return false;
            }
        }

        return true;
    }
};
