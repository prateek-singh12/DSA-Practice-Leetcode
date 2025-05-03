class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //using hashmap
        vector<int> hash(7,0);
        for(int i=0;i<tops.size();i++){
            hash[tops[i]]++;
            if(tops[i]!=bottoms[i]){ //distinct values
                hash[bottoms[i]]++;
            }
        }
        
        int res=INT_MAX;
        for(int i=1;i<=6;i++){
            if(hash[i]==tops.size()){
                int swaptop=0;
                int swapbottom=0;
                for(int j=0;j<tops.size();j++){
                    // if (tops[j] != i && bottoms[j] != i) {
                    //     swaptop = INT_MAX;
                    //     break;
                    // }
                    if(tops[j]!=i){
                        swaptop++;
                    }
                    else if(bottoms[j]!=i){
                        swapbottom++;
                    }
                }
                res=min(res,min(swapbottom,swaptop));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};