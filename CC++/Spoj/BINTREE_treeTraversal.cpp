#include <iostream>
#include <vector>
using namespace std;

void post(int pre[], int in[], int node, int high) {
    int left = node, right = high + 1;
    for (int i = node + 1; i <= high; i++)
        if (in[ pre[i] ] < in [ pre[node] ]) {
            left = i;
            break;
        }
    for (int i = left; i <= high; i++)
        if (in [ pre[i] ] > in[ pre[node] ]) {
            right = i;
            break;
        }
    
    if (left != node)
        post(pre, in, left, right - 1);

    if (right != high + 1)
        post(pre, in, right, high);

    cout << pre[node] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    int pre[n], in[n + 1];
    
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    
    for (int i = 0; i < n; i++) {
        int x;  cin >> x;
        in[x] = i;
    }

    post(pre, in, 0, n - 1);
}