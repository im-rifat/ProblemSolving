

int search(int* nums, int numsSize, int target) {
    int start = 0, end =  numsSize - 1;
    
    while(start <= end) {
        int mid = start + ((end - start) / 2);
        
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) {
            end = mid - 1;
        } else {
            start = start + 1;
        }
    }
    
    return -1;
}

