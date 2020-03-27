

bool checkIfExist(int* arr, int arrSize){
    for(int i = 0; i < arrSize; i++) {
        int doub = arr[i] * 2;
        int pos = i;
        
        for(int j = 0; j < arrSize; j++) {
            if(doub == arr[j] && pos != j) return true;
        }
    }
    
    return false;
}

