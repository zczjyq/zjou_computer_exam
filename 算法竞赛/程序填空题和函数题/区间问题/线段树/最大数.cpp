#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2e5 +  10;

int m, p;

struct {
    int l, r;
    int v;
} tr[N * 4];

void pushup(int u) {
    tr[u].v = max(tr[u >> 1].v, tr[u >> 1 | 1].v);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) return ;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int main() {
    cin >> m >> p;

    int x = 0, last = 0;
    build(1, 1, m);
    int n = 0;
    for (int i = 0; i < n; i ++ ) {
        char op[4];
        int x;
        cin >> op >> x;
        if (op == "Q") {
            last = query(1, n - x + 1, n);
            cout << last << endl;
        } else {
            modify(1, n + 1, ((ll) x + last) % p);
            n ++;
        }
    }
}