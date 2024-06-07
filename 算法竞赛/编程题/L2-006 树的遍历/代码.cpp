#include <iostream>

using namespace std;

const int N = 3500;

int n;
int back[N], mid[N];
int res[N][N];

void build(int b_l, int b_r, int m_l, int m_r, int deep) {
    if (b_l > b_r) return;
    
    int pos = m_l, root = back[b_r];
    res[deep][++res[deep][0]] = root;
    while (mid[pos] != root) pos ++ ;
    build(b_l, b_l + pos - 1 - m_l, m_l, pos - 1,deep + 1);
    build(b_l + pos - m_l, b_r - 1, pos + 1, m_r, deep + 1);
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> back[i];
    for (int i = 1; i <= n; i ++ ) cin >> mid[i];
    // 建树
    build(1, n, 1, n, 0);
    for (int i = 0; res[i][0] != 0; i ++ ) {
        for (int j = 1; j <= res[i][0]; j ++ ) {
            if (i == 0) cout << res[i][j];
            else cout << ' ' << res[i][j];
        }
    }
}