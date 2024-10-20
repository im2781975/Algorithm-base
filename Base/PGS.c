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
void RicercaBinaryNonRecursive(int arr[], int n, int val){
    int l = 0, r = n - 1;
    int mid =(l + r)/2;
    while(l != r){
        if(arr[mid] == val)
            return mid;
        if(arr[mid] < val)
            l = mid + 1;
        else
            r = mid - 1;
        mid = (l + r)/2;
    }
    return (arr[mid] == val) ? mid : -1;
}
/***/
def RicercaLineare(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1
/***/
def RicercaBinary(arr, key):
   l = 0, r = len(arr)
   mid = (l + r)//2
   while True:
       if mid < 0 || mid >= len(a):
           return -1
        if arr[mid] == val:
            return mid
        if arr[mid] < val:
            l = mid + 1
        else:
            r = mid - 1
        mid = (l + r)//2
/***/
int main(){
    int arr[8] = {41, 37, 10, 74, 98, 22, 83, 66};
    int n = 8;
    for(int i = n - 1; i >= 0; i--){
        int maxi = i;
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] > arr[maxi])
                maxi = j;
        }
        if(maxi != i){
            int tmp = arr[i];
            arr[i] = arr[maxi];
            arr[maxi] = tmp;
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
/***/
arr = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8
for i in range(n - 1, -1, -1):
    maxi = i
    for j in range(i - 1, -1, -1):
        if arr[j] > arr[maxi]:
            maxi = j
    if maxi != i:
        tmp = arr[i]
        arr[i] = arr[maxi]
        arr[maxi] = tmp
print(arr)
/***/
arr = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8
for i in range(1, n):
    val = arr[i]
    j = i - 1
    while(j >= 0 and arr[j] > val):
        arr[j + 1] = arr[j];
        j = j - 1
    arr[j + 1] = val
print(arr)
/***/
int main(){
    int arr[8] = {41, 37, 10, 74, 98, 22, 83, 66};
    int n = 8;
    for(int i = 1; i < n; i++){
        int val = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > val){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
/***/
int main(){
    int arr[8] = {41, 37, 10, 74, 98, 22, 83, 66};
    int n = 8;
    bool swap = true;
    while(swap){
        swap = false;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1]){
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swap = true;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
/***/
arr = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8
swap = True
while(swap):
    swap = False
    for i in range(n - 1):
        if arr[i] > arr[i + 1]:
            tmp = arr[i]
            arr[i] = arr[i + 1]
            arr[i + 1] = tmp
            swap = True
print(arr)
/***/
#include<iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r){
    int i = l, j = mid + 1, k = 0;
    int tmp[r - l + 1];
    for(int i = 0; i < (r - l + 1); i++)
        tmp[i] = 0;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            tmp[k] = arr[i]; i++;
        }
        else{
            tmp[k] = arr[j]; j++;
        }
        k++;
    }
    while(i <= mid){
        tmp[k] = arr[i];
        i++; k++;
    }
    while(j <= r){
        tmp[k] = arr[j];
        j++; k++;
    }
    for(k = l; k <= r; k++)
        arr[k] = tmp[k - l];
}
void mergesort(int arr[], int l, int r){
    if(l < r){
        int mid = (l + r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main(){
    int arr[8] = {41, 37, 10, 74, 98, 22, 83, 66}; 
    int n = 8;
    mergesort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
/***/
def merge(arr, l, mid, r):
    i = l
    j = mid + 1
    k = 0
    tmp = [0] * (r - l + 1)
    
    while i <= mid and j <= r:
        if arr[i] <= arr[j]:
            tmp[k] = arr[i]
            i+= 1
        else:
            tmp[k] = arr[j]
            j+= 1
        k+= 1
    while i <= mid:
        tmp[k] = arr[i]
        i += 1
        k += 1
    while j <= r:
        tmp[k] = arr[j]
        j+= 1
        k+= 1
    for k in range(l, r + 1):
        arr[k] = tmp[k - l]
def mergesort(arr, l, r):
    if(l < r):
        mid = (l + r)//2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);

arr = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8
mergesort(arr, 0, n - 1);
print(arr)
/***/
def quicksort(arr, l, r):
    i = l
    j = r
    pivot = arr[(l + r) //2]
    while i <= j:
        while arr[i] < pivot:
            i+= 1
        while arr[j] > pivot:
            j-= 1
        if i <= j:
            if i < j:
                tmp = arr[i]
                arr[i] = arr[j]
                arr[j] = tmp
            i += 1
            j -= 1
    if l < j:
        quicksort(arr, l, j)
    if i < r:
        quicksort(arr, i, r)
arr = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8
quicksort(arr, 0, n - 1);
print(arr)
/***/
void quicksort(int arr[], int l, int r){
    int i = l, j = r;
    int pivot = arr[(l + r)/2];

    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            if(i < j){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++; j--;
        }
    }
    if(l < j)
        quicksort(arr, l, j);
    if(i < r)
        quicksort(arr, i, r);
}
int main(){
    int arr[8] = {41, 37, 10, 74, 98, 22, 83, 66}; 
    int n = 8;
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
/***/
#include <iostream> 
using namespace std; 
void heapify(int a[],int sx,int dx){
    int temp=a[sx], i=sx, j= 2*i;
    while (j <= dx){    
        if((j < dx) && (a[j + 1] > a[j]))      
            j++;    
        if (temp < a[j]) {       a[i] = a[j];      
            i = j;      
            j = 2 * i;     
        } 
        else       
            j = dx + 1;   
    }      
    if (i != sx)   
    a[i] = temp;
}  
void heapsort(int a[], int n) {   int tmp,sx,dx;
    for (sx = n / 2;sx >= 1;sx--)     heapify(a,sx,n); 
    for (dx = n;dx > 1;dx--){     tmp = a[1];     
        a[1] = a[dx];     
        a[dx] = tmp;    
        heapify(a,1,dx - 1);   
    } 
}
int main(){
    int a[]={0, 42, 38, 11, 75, 99, 23, 84, 67};   
    int n=8;  
    heapsort(a,n);   
    for (int i=1;i<n+1;i++)     cout<<a[i]<<" "; 
}  
/***/
def heapify(a,sx,dx):      
    temp=a[sx]   
    i=sx   
    j= 2*i      
    while j <= dx:     
        if j < dx and a[j + 1] > a[j]:       
            j+=1     
        if temp < a[j]:       
            a[i] = a[j]       
            i = j       
            j = 2 * i     
        else:       
            j = dx + 1      
    if i != sx:     
        a[i] = temp    
def heapsort(a,n): 
    for sx in range(n//2,0,-1):     heapify(a,sx,n)     
    for dx in range(n,1,-1):     tmp = a[1]     
        a[1] = a[dx]     
        a[dx] = tmp     
        heapify(a,1,dx-1)   
a=[0, 42, 38, 11, 75, 99, 23, 84, 67]
n=8 
heapsort(a,n)
print(a) 
/***/
int main() {
    int* int_ptr_malloc = (int*) malloc(sizeof(int));
    *int_ptr_malloc = 5; 
    cout<<"Valore puntato: "<<*int_ptr_malloc<<endl; 
    free(int_ptr_malloc);
    int* int_ptr_new = new int; 
    *int_ptr_new = 10;
    cout <<"Valore puntato: "<<*int_ptr_new<<endl; 
    delete int_ptr_new; 
    return 0;
}
/***/
int main(){ 
    list root=NULL, aux;  
    char n;  
    while ((n=getchar()) != '\n'){ aux=(list)malloc(sizeof(struct list_element));  
        aux->value=n;  
        aux->next=root;  
        root=aux; 
    }   
} 
