#include <stdio.h>

#define N 110

int main()
{
    int n, m;
    int f[N];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);

    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d", f[(i + m) % n]);
        else printf(" %d", f[(i + m) % n]);
    }

    return 0;
}
