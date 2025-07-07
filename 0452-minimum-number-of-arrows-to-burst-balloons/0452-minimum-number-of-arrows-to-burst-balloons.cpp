class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        auto comp=[&](vector<int> a, vector<int> b){
            return a[1]<b[1];
        };
        
        sort(points.begin(), points.end(),comp);

        int arrows = 1;
        int lastArrow = points[0][1]; 

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > lastArrow) {
                arrows++;
                lastArrow = points[i][1]; 
            }
        }

        return arrows;
    }
};
