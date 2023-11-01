#include <stdio.h>

int prod(int m, int n) {
    if (n == 0) {
        return 0;
    } else if (n > 0) {
        return m + prod(m, n-1);
    } else { // n < 0
        return -prod(m, -n);
    }
}

int main() {
    int m = 2, n = 3;
    printf("%d * %d = %d\n", m, n, prod(m, n));
    return 0;
}

