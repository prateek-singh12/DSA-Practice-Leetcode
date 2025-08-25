class Solution {
public:
    void merge(vector<int>& arr1, int size1, vector<int>& arr2, int size2) {
        int a = 0, k = size1;
    while (a < size2) {
            arr1[k++] = arr2[a++];
        } 
    int i, j, temp, flag = 0;
    for(i=0; i<k; i++)
    {
    for(j=0; j<k-i-1; j++)
    {
        if(arr1[j]>arr1[j+1])
        {
        flag = 1;
        temp = arr1[j+1];
        arr1[j+1] = arr1[j];
        arr1[j] = temp;
        }
    }
    if(flag == 0) // array is sorted
    return; 
    }
    }
};