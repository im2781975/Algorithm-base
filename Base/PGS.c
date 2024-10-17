/***/
int RicercaSequential(int *arr, int len, int val){
    int i = 0;
    while(i < len){
        if(arr[i] == val)
            return i;
        i++;
    }
    return -1;
}
/***/
int RicercaBinarySplit(int *arr, int val, int l, int r){
    if(r < l)
        return -1;
    else{
        int mid = (l + r) / 2;
        if(arr[mid] == val)
            return mid;
        if(mid == 0)
            return -1;
        else if(val < arr[mid])
            return RicercaBinarySplit(arr, val, l, mid - 1);
        else
            return RicercaBinarySplit(arr, val, mid + 1, r);
    }
}
/***/
