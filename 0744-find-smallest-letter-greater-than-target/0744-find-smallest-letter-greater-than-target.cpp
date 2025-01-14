class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int last=n;
        if(target > letters[last-1]){ return letters[0];}
        int first= 0;
        while(first<=last){
            int mid = first + (last-first)/2;
            if(letters[mid] == target){return letters[mid+1];}
            else if(letters[mid] > target){
                last = mid-1;
            }
            else
                first=mid+1;
        }
        return letters[0];
    }
};