#include "binaryTree.hpp"
#include "maxHeap.hpp"
using namespace std;

int main() {
    int arr[] = {4, 3, 6, 2, 5, 7, 8, 5, 1};

    // binaryTree t;
    // for (int i : arr)
    //     t.insert(i);
    // t.preOrder();
    // t.erase(3);
    // t.preOrder();

    maxHeap h;
    for (int i : arr)
        h.push(i);
    while (!h.empty()) {
        cout << h.pop() << " ";
    }
}