#include <vector>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class MaxHeap {
    private:
    vector<int> heap;
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    void delet(int index) {
        if (index < 0 || index >= heap.size()) {
            cout << "Index out of range" << "\n";
            return;
        }
        heap[index] = INT_MAX; // Set to a very large value
        heapifyUp(index);
        getMax(); // Remove the max element from the root
    }
    int getMax() {
        if (heap.empty()) {
            cout << "Heap is empty" << "\n";
            return -1; // Or any suitable error value
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }
};
class MinHeap {
    private:
    vector<int> heap;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent= (idx - 1) / 2;
            if (heap[idx] < heap[parent]) {
                swap(heap[idx], heap[parent]);
                idx = parent;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int idx) {
        int left= 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != idx) {
            swap(heap[idx], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    // Remove and return the top (minimum) element
    int pop() {
        if (heap.empty())
            cout << "\nQueue is empty.";
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return top;
    }
    // Return the top (minimum) element without removing it
    int top() {
        if (heap.empty()) {
            throw std::runtime_error("Priority Queue is empty");
        }
        return heap[0];
    }
    bool empty() {
        return heap.empty();
    }
};
int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(30);

    cout << "Max: " << maxHeap.getMax() << "\n";

    maxHeap.delet(1);
    cout << "Max after deletion: " << maxHeap.getMax() << "\n";
    
    MinHeap minHeap;
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(8);
    minHeap.push(1);

    cout << "Top element: " << minHeap.top() << "\n";

    while (!minHeap.empty()) {
        cout << "Popped: " << minHeap.pop() << "\n";
    }
    return 0;
}
