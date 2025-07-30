class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum=0;int costsum=0;
        for(auto it1:gas){gassum+=it1;}
        for(auto it2:cost){costsum+=it2;}
        if(costsum>gassum){return -1;}

        int ans = 0;
    int sum = 0;

    // Try to start from each index.
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        ans = i + 1;  // Start from the next index.
      }
    }

    return ans;
  
        
    }
};