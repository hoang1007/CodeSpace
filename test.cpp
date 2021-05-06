#include <iostream>
#include <map>
using namespace std;

map<int , string> q;

void init()
{
	string list[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
					"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
					"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
					"hundred", "thousand", "milion"};
	
	for (int i = 0; i <= 20; i++)
		q[i] = list[i];
	
	for (int i = 0, int j = 30; i <= 28, j += 10)
		q[j] = list[i];
	q[1000] = list[29];
	q[1000000] = list[30];
}

int main()
{
	init();
	cout << q[30];
}