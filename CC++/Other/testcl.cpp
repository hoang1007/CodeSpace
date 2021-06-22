#include<bits/stdc++.h>
using namespace std;

long long binary(long long a[], long long x,long long n)
{
    long long left = 0, right = n-1;
    long long distance = 1e9+10;
    long long res = -1;
    while(left <= right)
    {
        long long mid = (left + right)/2;
        if(x == a[mid]) return mid;
        else if(x < a[mid])
        {
            long long space  = a[mid] - x;
            if(space < distance)
            {
                distance = space;
                res = mid;
            }
            right = mid - 1;
        }
        else
        {
            long long space = x - a[mid];
            if(space < distance)
            {
                distance = space;
                res = mid;
            }
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    long long n,q;
    cin>> n >> q;
    long long a[n];
    for(long long i = 0 ; i < n; i++)
    {
        cin>> a[i];
    }
    sort(a,a+n);
    while(q--)
    {
        long long x,k;
        cin>> x >> k;
        long long i = binary(a,x,n);
        
        long long left = i-1, right = i;
        
        while(k--)
        {
            if (left >= 0 && right < n) {
                long long leftspace = a[i]-a[left];
                long long rightspace  = a[right]-a[i];

                if (leftspace <= rightspace) {
                    cout << a[left] << " ";
                    left--;
                }
                else {
                    cout << a[right] << " ";
                    right++;
                }
            }
            else if (left >= 0) {
                cout << a[left] << " ";
                left--;
            }
            else if (right < n) {
                cout << a[right] << " ";
                right++;
            }
        }
        cout<< endl;
    }
}