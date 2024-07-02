#include<bits/stdc++.h>
using namespace std;
class Array{
    public:
    int *arr, cap, size;
    void Increase(){
        cap *= 2;
        int *tmp = new int[cap];
        for(int i = 0; i < size; i++)
            tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
    }
    void Decrease(){
        cap /= 2;
        int *tmp = new int[cap];
        for(int i = 0; i < size; i++)
            tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
    }
    Array(){
        arr = new int[1];
        cap = 1; size = 0;
    }
    void PushBack(int x){
        if(size == cap)
            Increase();
        arr[size] = x;
        size++;
    }
    void Insert(int pos, int x){
        if(size == cap)
            Increase();
        for(int i = size - 1; i >= pos; i--)
            arr[i+1] = arr[i];
        arr[pos] = x;
        size++;
    }
    void print(){
        cout << "\nElements are: ";
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
    int getsize(){
        return size;
    }
    int get(int idx){
        if(idx >= size){
            cout << "\nElement didn't Exits";
            return -1;
        }
        return arr[idx];
    }
    void getElement(Array a){
        cout << "\nElements are: ";
        for(int i = 0; i < a.getsize(); i++)
            cout << a.get(i) << " ";
    }
    void PopBack(){
        if(size <= cap/2)
            Decrease();
        if(size == 0)
            cout << "\nNULL";
        size--;
    }
    void Erase(int idx){
        if(size <= cap/2)
            Decrease();
        if(idx >= size)
            cout << "\nElements didn't Exits";
        for(int i = idx + 1; i < size; i++)
            arr[i -1] = arr[i];
        size--;
    }
};
int main(){
    Array a;
    for(int i = 10; i < 70; i+= 10)
        a.PushBack(i);
    a.print();
    a.Insert(2, 3);
    a.print();
    a.Erase(4);
    a.print();
    for(int i = 0; i < 3; i++){
        a.PopBack();
        a.print();
    }
    a.getElement(a);
    cout << "\nElements are: ";
    for(int i = 0; i < a.getsize(); i++)
        cout << a.get(i) << " ";
}
