class Solution {
    
    private int linearSearch(int[] A, int target) {
        for(int i = 0; i < A.length; i++) {
            if(A[i] == target) return i;
        }
        
        return -1;
    }
    
    public int[] twoSum(int[] nums, int target) {
        //Arrays.sort(nums);
        
        for(int i = 0; i < nums.length; i++) {
            int one = i;
            int two = linearSearch(nums, target - nums[one]);
            
            if(two >= 0 && one != two) {
                return new int[] {one, two};
            }
        }
        
        return null;
    }
}