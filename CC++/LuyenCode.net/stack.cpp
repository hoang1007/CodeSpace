#include <cstdio>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int t;  scanf("%d", &t);
    while (t--) {
        int x;  scanf("%d", &x);
        switch (x) {
        case 1: {
            int n;  scanf("%d", &n);
            s.push(n);
        }
            break;
        case 2: 
            if (!s.empty()) s.pop();
            break;
        case 3:
            if (s.empty()) printf("Empty!\n");
            else printf("%d\n", s.top());
        default:
            break;
        }
    }
}