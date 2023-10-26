#include <iostream>
#include <vector>

template <typename T>
class MinHeap {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(T value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void delete(int index) {
        if (index < 0 || index >= heap.size()) {
            return;
        }
        heap[index] = heap.back();
        heap.pop_back();
        heapifyDown(index);
        heapifyUp(index);
    }

    T getMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty.");
        }
        return heap[0];
    }
};

int main() {
    MinHeap<int> minHeap;

    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);
    minHeap.insert(6);

    std::cout << "Min Element: " << minHeap.getMin() << std::endl;

    minHeap.delete(1);

    std::cout << "Min Element after deleting index 1: " << minHeap.getMin() << std::endl;

    return 0;
}

