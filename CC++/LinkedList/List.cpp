#include "List.hpp"
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    // cout << "Press 1 to insert position\n";
    // cout << "Press 2 to insert back\n";
    // cout << "Press 3 to erase position\n";
    // cout << "Press 4 to erase back\n";
    // cout << "Press 5 to print\n";
    // cout << "Press 6 to quit\n";
    List list = List(arr, sizeof(arr)/sizeof(*arr));
    
    cout << list;
    list.pop_back();
    cout << list;
    // bool running = true;
    // while (running) {
    //     int key; cin >> key;
    //     switch (key)
    //     {
    //     case 1: {
    //         cout << "nhap vi tri muon insert: ";
    //         int pos; cin >> pos;
    //         cout << "nhap gia tri muon insert: ";
    //         int value; cin >> value;
    //         list.insert(pos, value);
    //     }
    //         break;
    //     case 2: {
    //         cout << "nhap vi tri muon insert back: ";
    //         int value; cin >> value;
    //         list.push_back(value);
    //     }
    //         break;
    //     case 3: {
    //         cout << "Nhap vi tri muon xoa: ";
    //         int pos;    cin >> pos;
    //         list.erase(pos);
    //     }
    //         break;
    //     case 4: {
    //         cout << "Dang xoa back...";
    //         list.pop_back();
    //     }
    //         break;
    //     case 5: {
    //         cout << list;
    //         cout << "Printed" << endl;
    //     }
    //         break;
    //     case 6: {
    //         running = false;
    //     }
    //         break;
    //     default:
    //         break;
    //     }
    // }
}