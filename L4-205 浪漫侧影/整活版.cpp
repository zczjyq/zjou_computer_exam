#include <iostream>
#include <queue>
using namespace std;
const int N = 25;
int n, c, r[N], p[N], d;
int res[N][N];
queue <int> q;
struct node {
    int v, l = -1, r = -1;
}y[N];

int build(int r_l, int r_r, int p_l, int p_r) {
    if (r_l > r_r) return -1;
    int idx = c ++, pos = r_l ;
    y[idx].v = p[p_r];
    while (r[pos] != p[p_r]) pos++;
    y[idx].l = build(r_l, pos - 1, p_l, p_l + pos - 1 - r_l);
    y[idx].r = build(pos + 1, r_r, p_l + pos - r_l, p_r - 1);
    return idx;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> r[i];
    for (int i = 1; i <= n; i ++ ) cin >> p[i];

    build(1, n, 1, n);
    q.push(0);
    while (!q.empty()) {
        for (int i = q.size(); i > 0; i -- ) {
            int j = q.front(); q.pop();
            res[d][ ++ res[d][0]] = y[j].v;
            if (y[j].l != -1) q.push(y[j].l);
            if (y[j].r != -1) q.push(y[j].r);
        }
        d ++ ;
    }
    cout << "R:";
    for (int i = 0; i < d; i ++ ) cout << ' ' << res[i][res[i][0]];
    cout << endl << "L:";
    for (int i = 0; i < d; i ++ ) cout << ' ' << res[i][1];
    cout << endl;
}