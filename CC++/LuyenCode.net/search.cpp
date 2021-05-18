#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> arr;
    int n1, n2; cin >> n1 >> n2;
    while (n1--) {  
        int x;  cin >> x;
        arr[x] = 1;
    }
    
    while (n2--) {
        int x;  cin >> x;
        cout << arr[x];
    }
}