class Solution {
public:
int get_ans(long long &k,long long curr,int i,vector<int>&op){
    if(k==1) return 0;
    int count=0;
    if(k<=curr){
        k=k-((long long)curr/2);
        if(op[i]==1) return 1;
        return 0;
    } 

    count=get_ans(k,curr*2,i+1,op);

    long long exp=pow(2,ceil(log2(k)));

   

    if(exp==curr){
        k=k-((long long)curr/2);
        if(op[i]==1) return count+1;
        return count;
    } 

    return count;
}
    char kthCharacter(long long k, vector<int>& operations) {
        return (get_ans(k,2,0,operations)%26)+'a';
    }
};