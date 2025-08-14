// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int l=0;
//         int r= height.size()-1;
//         int ans=0;
//         while(l<r){
//             int area=(r-l)*min(height[l],height[r]);
//             ans=max(ans,area);
//             if (height[l] <= height[r])
//                 l++;
//             else
//                 r--;
//         }
//         return ans;        
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=(r-l)*min(height[r],height[l]);
        while(l<r){
            
            if(height[r]>=height[l]) l++;
            else if(height[r]<height[l]) r--;
            int currarea= (r-l)*min(height[r],height[l]);
            area=max(area,currarea);
        }        
        return area;
    }
};