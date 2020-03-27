class Solution {
    public boolean validMountainArray(int[] A) {
        if(A.length < 3) return false;
        
        boolean peak = false;
        int i = 0;
        
        for(int j = 0; !peak && j < A.length - 1; j++) {
            if(A[j] < A[j+1]) {
            } else {
                if(j == 0) {
                    break;
                }
                peak = true;
                
                //System.out.println(peak + " " + j);
                i = j;
            }
        }
        
        if(!peak) return false;
        
        for(int j = i ;j < A.length - 1; j++) {
            if(A[j] > A[j+1]) {}
            else return false;
        }
        
        return true;
    }
}