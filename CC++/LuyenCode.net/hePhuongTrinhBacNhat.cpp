#include <stdio.h>

void print(double x, double y) {
    if (x == 0) x = 0;
    if (y == 0) y = 0;
    printf("%.2lf %.2lf", x, y);
}

int main() {
    int a, b, c, d, e, f;
    /*
        ax + by = c
        dx + ey = f
    */

    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    double fa, fb;
    // case d = 0
    if (d == 0) {
        fa = (double) e - b;
        fb = (double) f - c;
    }
    else {
        double a_d = (double) a/d;
        fa = (double) a_d*e - b;
        fb = (double) a_d*f - c;
    }

    if (fa == 0 && fb == 0) {
        printf("VOSONGHIEM");
        return 0;
    }

    if (fa == 0 && fb != 0) {
        printf("VONGHIEM");
        return 0;
    }

    if (a == 0) printf("VOSONGHIEM");
    else {
        double y = fb / fa;
        double x = (double) (c - b*y)/a;
        print(x, y);
    }
}

/*
80210 68093 -56814
80210 34046 -56814
*/