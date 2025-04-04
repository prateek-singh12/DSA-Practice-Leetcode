class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {   
    vector<vector<int>> result;
    int m=nums1.size();
    int n=nums2.size();
    int i=0,j = 0;
    while(i < m && j < n) {
        if(nums1[i][0] < nums2[j][0]) {
            result.push_back(nums1[i]);
            i++;
        } else if(nums2[j][0] < nums1[i][0]) {
            result.push_back(nums2[j]);
            j++;
        } else { //when id is equal
            result.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
            i++;
            j++;
        }
    }
    // for remainng part
    while(i < m) {
        result.push_back(nums1[i]);
        i++;
    }
    while(j < n) {
        result.push_back(nums2[j]);
        j++;
        }  
    return result; 
    }
};