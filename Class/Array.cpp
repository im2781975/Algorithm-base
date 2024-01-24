#include<bits/stdc++.h>
using namespace std;
class Array
{
    public:
    int *arr;
    int cap;
    int size;
    void increase()
    {
        cap=cap*2;
        int *tmp=new int[cap];
        for(int i=0; i<size; i++)
            tmp[i]=arr[i];
        delete [] arr;
        arr = tmp;
    }
    void decrease()
    {
        cap=cap/2;
        int *tmp=new int[cap];
        for(int i=0; i<size; i++)
            tmp[i]=arr[i];
        delete [] arr;
        arr=tmp;
    }
    Array()
    {
        arr=new int[1];
        cap=1;
        size=0;
    }
    void Push_back(int x)
    {
        if(size==cap)
            increase();
        arr[size]=x;
        size++;
    }
    void Insert(int pos, int x)
    {
        if(cap==size)
            increase();
        for(int i=size-1; i>=pos; i--)
            arr[i+1]=arr[i];
        arr[pos] = x;
        size++;
    }
    void Print()
    {
        cout << "\nElements are: ";
        for(int i=0; i<size; i++)
            cout << arr[i] << " ";
    }
    int getSize()
    {
        return size;
    }
    int get(int idx)
    {
        if(idx>=size)
        {
            cout <<"Elements aren't exists";
            return -1;
        }
        return arr[idx];
    }
    void getElement(Array a)
    {
        cout <<"\nElements are: ";
        for(int i=0; i<a.getSize(); i++)
            cout << a.get(i) << " ";
    }
    void Pop_back()
    {
        if(size<=cap/2)
            decrease();
        if(size==0)
            cout << "Null";
        size--;
    }
    void Erase(int idx)
    {
        if(size<=cap/2)
            decrease();
        if(idx>=size)
            cout <<"Does'nt exit";
        for(int i=idx+1; i<size; i++)
            arr[i-1]=arr[i];
        size--;
    }
};
int main()
{
    Array a;
    a.Push_back(1);
    a.Print();
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(50);
    a.Insert(1,5);
    a.Print();

    cout<<"\nSize is: "<<a.getSize()<<" ";

    a.Pop_back();
    a.Print();
    a.Pop_back();
    a.Print();
    a.Erase(1);
    a.Print();
    a.getElement(a);
    cout << "\n";
    for(int i=0; i<a.getSize(); i++)
        cout <<a.get(i) << " ";
}
