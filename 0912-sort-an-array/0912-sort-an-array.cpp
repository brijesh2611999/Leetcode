class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        int l_size = mid-low+1;
        int r_size = high-mid;
        int l[l_size],r[r_size];
        for(int i=0; i<l_size; i++){
            l[i] = nums[low+i];
        }
        for(int j=0; j<r_size; j++){
            r[j] = nums[mid+j+1];
        }
        int i=0,j=0,k=low;
        while(i<l_size && j<r_size){
            if(l[i]<=r[j]){
                nums[k] = l[i++];
            }
            else{
                nums[k] = r[j++];
            }
            k++;
        }
        while(i<l_size) nums[k++] = l[i++];
        while(j<r_size) nums[k++] = r[j++];
    }
    void mergeSort(vector<int>& nums, int low , int high){
        if(low < high){
            int mid = low + ( high - low )/2;
            mergeSort(nums,low, mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low, mid, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};