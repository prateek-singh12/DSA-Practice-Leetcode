class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        //taking hours from 0 to max element        
        while(l<r){
            int mid=l+(r-l)/2;
            int hour=0;
            for(int bananas: piles){
                hour+=bananas/mid;
                if(bananas%mid != 0) //not divisible -> for taking ceil add ++
                    hour++;
            }
            if(hour<=h){                
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};

