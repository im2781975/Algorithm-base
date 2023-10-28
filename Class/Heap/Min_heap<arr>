#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is smaller than the root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        
        minHeapify(arr, n, smallest);
    }
}

void heapSort(vector<int> &arr) 
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);

        // Call minHeapify on the reduced heap
        minHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    heapSort(arr);

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
