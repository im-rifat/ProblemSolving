
int singleNumber(int* nums, int numsSize){
    int item = 0;
    for(int i = 0; i < numsSize; i++) {
        item ^= nums[i];
    }
    
    return item;
}
