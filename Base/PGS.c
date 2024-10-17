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
int RecursiveMin(int arr[], int len, int l, int r){
    if(l == r)
        return arr[l];
    else {
        int mean = (l + r)/2;
        return min(RecursiveMin(arr, len, l, mean), RecursiveMin(arr, len, mean + 1, r));
    }
}
/***/
void Hanoi(int n, int A, int C, int B){
    if(n == 1)
        cout << A << " " << C << "\n";
    else{
        Hanoi(n, A, B, C);
        cout << A << " " << C << "\n";
        Hanoi(n, B, C, A);
    }
}
int main(){
    Hanoi(3, 1, 3 , 2);
}
/***/
int Fib(int n){
    if(n == 1 || n == 2)
        return 1;
    int first = 1, second = 1, fib;
    for(int i = 3; i <= n; i++){
        fib = first + second;
        first = second;
        second = fib;
    }
    return fib;
}
/***/
int Fib(int n){
    int fib;
    if(n == 1 || n == 2)
        fib = 1;
    else
        fib = Fib(n - 1) + Fib(n - 2);
    return fib;
}
/***/
int fattorial(int n){
    int fatt;
    if(n == 1)
        fatt = 1;
    else
        fatt = n * fattorial(n - 1);
    return fatt;
}
/***/
from array import *
a = [0] * 10
b = ['A', ' ', 'B', 30, 40]
print(a, b)
arr = array('i', [10, 20, 30])
arr[2] = 80
for x in arr:
    print(x)
/***/
int main(){
    int *p = NULL;
    p = new int[100];
    for(int i = 0; i < 100; i++)
        p[i] = rand();
    delete []p;
    for(int i = 0; i < 100; i++)
        cout << p[i] << " ";
}
/***/
