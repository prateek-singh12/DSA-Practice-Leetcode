class Solution {
public:

    bool isPrime(int n){
    if (n==1)
        return false;
    if (n==2||n==3)
        return true;
    if ((n%2==0)||(n%3==0))
        return false;
    for (int i = 5; i*i <= n; i=i+6)
    {
        if ((n%i==0)||(n%(i+2)==0))
        {
            return false;
        }}
    return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int count=0;
        int mini=INT_MAX;
        int prev=-1;
        int next=0;
        int num1=-1,num2=-1;
        for(int i=left; i<=right; i++){
            if(isPrime(i)){
                int dist= i - prev;
                if(dist<mini){
                    mini=dist;
                    num1=prev;
                    num2=i;
                }
                prev=i; 
            }
        }
        if(num1==-1 || num2==-1){
            return {-1,-1};
        }
        return {num1,num2};
    }
};