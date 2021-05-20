#include <stdio.h>
#include <math.h>

typedef struct Coordinate {
    int x, y, z;
} coordinate;

int length(coordinate c) {
    return c.x*c.x + c.y*c.y + c.z*c.z;
}

int main() {
    int t;  scanf("%d", &t);
    while (t--) {
        coordinate p[3];
        for (int i = 0; i < 3; i++)
            scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
        
        // find direction vector
        coordinate direction;
        direction.x = p[2].x - p[1].x;
        direction.y = p[2].y - p[1].y;
        direction.z = p[2].z - p[1].z;

        coordinate am;
        am.x = p[0].x - p[1].x;
        am.y = p[0].y - p[1].y;
        am.z = p[0].z - p[1].z;

        int k = direction.x*am.x + direction.y*am.y + direction.z*am.z;

        double res = (double) length(direction) - (double) k*k/length(am);

        printf("%.2lf\n", sqrt(res));
    }
}