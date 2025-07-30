class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long r=1LL * (*min_element(time.begin(),time.end())) * totalTrips;

        while(l<r){
            long long mid=l+(r-l)/2;
            long long trips=0;
            for(int bustime: time){
                trips=trips+mid/bustime;
            }

            if(trips>=totalTrips){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};