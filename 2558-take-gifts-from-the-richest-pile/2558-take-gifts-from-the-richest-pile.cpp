class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0ll;
        priority_queue <int> res (gifts.begin(),gifts.end());
        for(int i=0;i<k;i++){
            int top=res.top();
            res.pop();
            res.push((int)sqrt(top));
        }
        for( int k: gifts){
            ans+=res.top();
            res.pop();
        }
        return ans;
    }
};