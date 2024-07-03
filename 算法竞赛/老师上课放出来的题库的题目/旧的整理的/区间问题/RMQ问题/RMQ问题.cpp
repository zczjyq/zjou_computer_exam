// https://www.acwing.com/problem/content/description/1275/
// 算法思路请见https://oi-wiki.org/ds/sparse-table/

#include <iostream>
#include <cmath>

using namespace std;

const int N = 2e5 + 10, M = 18;

int n, m;
int nums[N], f[N][M];

void init() {
    for (int j = 0; j < M; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) {
            if (j == 0) f[i][j] = nums[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
}

int query(int l, int r) {
    int len = r - l + 1;
    int k = log2(len);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> nums[i];
    init();
    cin >> m;
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}