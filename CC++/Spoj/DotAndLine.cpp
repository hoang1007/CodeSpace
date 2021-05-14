#include <iostream>
#include <vector>
using namespace std;

struct Coordinate
{
    int x, y;
};

vector<double> findLine(Coordinate a, Coordinate b)
{
    // neu x bang nhau
    if (a.x == b.x && a.y == b.y) return {0, 0};
    else if (a.x == b.x) return {(double) a.x, 0};
    else if (a.y == b.y) return {0, (double) a.y};
    else
    {
        double m = (double) (a.y - b.y) / (a.x - b.x);
        double n = (double) a.y - m * a.x;
        return {m, n};
    }
}

int main()
{
    int t;  cin >> t;
    while (t--)
    {
        Coordinate a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        vector<double> line = findLine(a, b);
        int n;  cin >> n;
        vector<Coordinate> dot(n);
        for (int i = 0; i < n; i++)
            cin >> dot[i].x >> dot[i].y;
        int count = 0;
        for (int i = 0; i < n; i++)
            if (line[0]*dot[i].x + line[1] == dot[i].y) count++;
        cout << count << endl;
    }
}