class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //maximum score = sum of all cards−minimum sum of a subarray of length (n−k)
        int n=cardPoints.size();
        int i=0;
        int j=0;
        int totalsum=0;
        int currsum=0;
        int minsum=INT_MAX;

        for(auto num:cardPoints) totalsum+=num;
        if(k==n) return totalsum;

        while(j<n){
            currsum+=cardPoints[j];
            while(j-i+1 > n-k){
                currsum-=cardPoints[i];
                i++;
            }
            if(j-i+1 == n-k){
                minsum=min(minsum, currsum);
            }
            j++;
        }
        return totalsum-minsum;

    }
};