#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

struct mat_2
{
    ll x1, y1, x2, y2;
    mat_2(ll _x1, ll _y1, ll _x2, ll _y2)
    {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
    mat_2()
    {
        x1 = 1; y1 = 0;
        x2 = 0; y2 = 1;
    }
    mat_2(const mat_2& src)
    {
        x1 = src.x1;
        x2 = src.x2;
        y1 = src.y1;
        y2 = src.y2;
    }

    friend mat_2 operator*(mat_2 a, mat_2 b)
    {
        return mat_2( (a.x1 * b.x1 + a.y1 * b.x2) % MOD , (a.x1 * b.y1 + a.y1 * b.y2) % MOD,
                (a.x2 * b.x1 + a.y2 * b.x2) % MOD, (a.x2 * b.y1 + a.y2 * b.y2) % MOD);
    }

    void print()
    {
        cout << x1 << " " << y1 << endl << x2 << " " << y2 << endl;
    }
    void operator=(const mat_2 &src)
    {
        x1 = src.x1;
        y1 = src.y1;
        x2 = src.x2;
        y2 = src.y2;
    }
};

struct mat_1
{
    ll x, y;
    mat_1()
    {
        x = 1;
        y = 0;
    }
    mat_1(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }

    friend mat_1 operator*(mat_2 a, mat_1 b)
    {
        return mat_1(a.x1 * b.x + a.y1 * b.y, a.x2 * b.x + a.y2 * b.y);
    }
    void print()
    {
        cout << x << endl << y << endl;
    }
};

mat_2 pow(mat_2 a, ll n)
{
    mat_2 res;
    for (; n; n /= 2, a = a * a)
        if (n % 2) res = res * a;
    return res;
}

void heapify(ll arr[], ll n, ll root)
{
    ll largest = root;
    ll left = 2 * root + 1,
        right = 2 * root + 2;
    
    //find the largest node in heap tree
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        heapify(arr, n, largest);
    }
}

void HeapSort(ll arr[], ll n)
{
    //build heap
    for (ll i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    //sort
    for (ll i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    mat_1 fibo_0_1(1, 0);   // fibo[0] = 0 & fibo[1] = 1; viet lai duoi dang ma tran
    mat_2 a(1, 1, 1, 0);    //ma tran phan tu cua fibo
    mat_2 res_pow;  // luu lai ma tran sau khi luy thua
    
    ll current_pow = 0; // luu lai so mu luy thua gan nhat

    ll t; cin >> t;
    ll *test = new ll[t], *test_copy = new ll[t];

    for (ll i = 0; i < t; i++)
    {
        cin >> test[i];
        test_copy[i] = test[i];
    }
    map<ll, ll> output;

    HeapSort(test_copy, t);
    for (ll i = 0; i < t; i++)
    {
        res_pow = res_pow * pow(a, test_copy[i] - current_pow);
        current_pow = test_copy[i];
        mat_1 res = res_pow * fibo_0_1;
        output[test_copy[i]] = res.y;
    }

    for (ll i = 0; i < t; i++)
        cout << output[test[i]] << endl;
}