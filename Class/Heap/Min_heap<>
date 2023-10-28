#include <bits/stdc++.h>
using namespace std;
class MinHeap {
    public:
    vector<int> heap;
    
    MinHeap() {}

    void insert(int x) {
        heap.push_back(x);
        int current = heap.size() - 1;

        while (current > 1 && heap[current] < heap[current / 2]) {
            swap(heap[current], heap[current / 2]);
            current = current / 2;
        }
    }
    
    void Delete(int idx) {
        if (idx < 1 || idx >= heap.size()) {
            return; 
        }

        // Replace the element at the specified index with the last element
        heap[idx] = heap.back();
        heap.pop_back();

        // Adjust the heap to maintain the min-heap property
        int current = idx;
        while (current < heap.size()) {
            int left = current * 2;
            int right = current * 2 + 1;
            int smallest = current;

            if (left < heap.size() && heap[left] < heap[current]) {
                smallest = left;
            }
            if (right < heap.size() && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != current) {
                std::swap(heap[current], heap[smallest]);
                current = smallest;
            } else {
                break;
            }
        }
    }

    // Get the minimum element (the root) of the min-heap
    int getMin() {
        if (heap.size() > 1) {
            return heap[1];
        } else {
            // The heap is empty
            return -1; // You can choose a different value to indicate an empty heap
        }
    }
};
int main() {
    MinHeap minHeap;

    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);
    minHeap.insert(10);

    int minElement = minHeap.getMin();
    if (minElement != -1) {
        cout << "Minimum element in the heap: " << minElement << endl;
    } else {
        cout << "Heap is empty." << endl;
    }

    int indexToDelete = 3;
    minHeap.Delete(indexToDelete);

    minElement = minHeap.getMin();
    if (minElement != -1) {
        cout << "Minimum element in the heap after deletion: " << minElement << endl;
    } else {
        cout << "Heap is empty." << endl;
    }

    return 0;
}
