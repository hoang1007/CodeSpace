#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;

	vector< vector<int>> pascal (n + 2, vector<int> (n + 2, 0));

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if (j == 0) pascal[i][j] = 1;
			pascal[i + 1][j + 1] = pascal[i][j] + pascal[i][j + 1];
		}
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (pascal[i][j]) 
				cout << pascal[i][j] << " ";
			else cout << " ";
		}
		cout << endl;
	}
}