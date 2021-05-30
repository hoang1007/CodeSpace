#ifndef _Max_Heap_hpp
#define _Max_Heap_hpp

#include <vector>
#include <iostream>
using namespace std;
class maxHeap {
    vector<int> data;
    void heapify(int nodeIndex);
public:
    void push(int value);
    int pop();
    int &top();
    void preOrder(int node = 0);
    void inOrder(int node = 0);
    void postOrder(int node = 0);
    bool empty();
};

void maxHeap::heapify(int nodeIndex) {
    int largest = nodeIndex,
        left = 2*nodeIndex + 1,
        right = 2*nodeIndex + 2;
    
    if (left < data.size() && data[left] > data[largest])
        largest = left;
    if (right < data.size() && data[right] > data[largest])
        largest = right;
    
    if (largest != nodeIndex) {
        swap(data[largest], data[nodeIndex]);
        heapify(largest);
    }
}

void maxHeap::push(int value) {
    data.push_back(value);
    for (int i = data.size()/2 - 1; i >= 0; i--)
        heapify(i);
}

int maxHeap::pop() {
    int returnValue = data[0];
    swap(data[0], data.back());
    data.pop_back();
    heapify(0);
    return returnValue;
}

int &maxHeap::top() {
    return data.front();
}

void maxHeap::preOrder(int node) {
    if (node >= data.size()) return ;
    cout << data[node] << " ";
    preOrder(2*node + 1);
    preOrder(2*node + 2);
}

void maxHeap::inOrder(int node) {
    if (node >= data.size()) return ;
    inOrder(2*node + 1);
    cout << data[node] << " ";
    inOrder(2*node + 2);
}

void maxHeap::postOrder(int node) {
    if (node >= data.size()) return ;
    postOrder(2*node + 1);
    postOrder(2*node + 2);
    cout << data[node] << " ";
}

bool maxHeap::empty() {
    return data.empty();
}
#endif