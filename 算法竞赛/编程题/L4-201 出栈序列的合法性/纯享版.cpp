#include <iostream>

using namespace std;

int m, n, k;

bool check() {
    int hh = -1, cnt = 1, s[1010], nums[1010];
    for (int i = 0; i < n; i ++ ) cin >> nums[i];
    for (int i = 0; i < n; i ++ ) {
        int x = nums[i];
        if (hh == -1 || x >= cnt) {
            while (x >= cnt) s[++ hh] = cnt ++ ;
            if (hh + 1 > m) return 0;
        } else if (s[hh] != x) return 0;
        hh --;
    }
    return 1;
}

int main() {
    cin >> m >> n >> k;
    while (k -- ) puts(check() ? "YES" : "NO");
}