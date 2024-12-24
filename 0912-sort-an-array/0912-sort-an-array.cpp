class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1; 
        int n2 = right - mid;   

        vector<int> leftArr(n1), rightArr(n2);

        // Copy data 
        for (int i = 0; i < n1; ++i) {
            leftArr[i] = nums[left + i];
        }
        for (int i = 0; i < n2; ++i) {
            rightArr[i] = nums[mid + i + 1];
        }
        // Merge
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }
        // for remaining elements
        while (i < n1) {
            nums[k++] = leftArr[i++];
        }
        while (j < n2) {
            nums[k++] = rightArr[j++];
        }
    }

    
};
