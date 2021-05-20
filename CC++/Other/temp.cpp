#include<bits/stdc++.h>
using namespace std;

struct data
{
	int value;
	int pos;
};

bool cmp(data a , data b)
{
	if(a.pos == b.pos) return a.value < b.value;
	if(a.pos > b.pos) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		vector<int> a(n);
		vector<int> ts(100005,0);
		vector<data> D(n);
		for(int i =0; i < n ;i++)
		{
			cin>> a[i];
			ts[a[i]]++;
			
		}
		for(int i = 0 ; i < n; i++)
		{
			D[i].value = a[i];
			D[i].pos = ts[a[i]];
		}
		sort(D.begin(),D.end(),cmp);
		for(int i = 0; i < n ;i++)
		{
			cout<< D[i].value << " ";
		}
		cout<< endl;
	}
	
}