#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2 * 123456 + 2;

vector<int> countPrime(MAX, 1);

void sieve_of_eratosthenes()
{
    for (int i = 2; i * i < MAX; i++)
    {
        for (int j = i * i; j < MAX; j += i)
            countPrime[j] = 0;
    }
    for (int i = 2; i < MAX; i++)
        countPrime[i] += countPrime[i - 1];
}

int main()
{
    countPrime[0] = countPrime[1] = 0;

    sieve_of_eratosthenes();

    int n;
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        cout << countPrime[2 * n] - countPrime[n] << endl;
    }
    return 0;
}