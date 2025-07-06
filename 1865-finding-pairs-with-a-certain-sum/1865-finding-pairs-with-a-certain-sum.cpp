class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        for (int num : nums1) {
            int complement = tot - num;
            result += freq2[complement];
        }
        return result;
    }
};


/*
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */