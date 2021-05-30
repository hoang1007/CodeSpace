#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int query;  cin >> query;
    char action;
    priority_queue<int> q;
    unordered_map<int, bool> has;
    while (query--) {
        cin >> action;
        if (action == '+' && q.size() < 15000) {
            int value;
            cin >> value;
            if (!has[value]) {
                q.push(value);
                has[value] = true;
            }
        }
        else if (action == '-' && !q.empty()) {
            has[q.top()] = false;
            q.pop();
        }
    }

    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}