#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int arr[] = {4, 1, 6, 3, 8, 9, 5};
    for (int i : arr)
        pq.push(i);
    
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}