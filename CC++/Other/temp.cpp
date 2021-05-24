#include<bits/stdc++.h>
using namespace std;
vector<char> a(100);
void Cout(int n)
{
    for(int i = 0; i < n ;i++)
    {
        cout<< a[i];
    }
    cout<< " ";
}
void Change(int n, int pos)
{
    for(int i = pos; i < n ;i++)
    {
        a[i] = 'A';
    }
}
void solve()
{
    int n;
    cin>> n;
    for(int i = 0; i < n; i++)
    {
        a[i] = 'A';
    }
    Cout(n);
    int i = n-1;
    while(i)
    {
        if(a[i] == 'B') i--;
        if(a[i] == 'A')
        {
            a[i] = 1;
            Change(n,i+1);
            Cout(n);
            i = n-1;
        }
    } 
}

int main()
{
    int t;
    // cin>> t;
    // while(t--)
    {
        solve();
        cout<< endl;
    }   
    return 0;
}