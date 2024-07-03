#include <iostream>

using namespace std;

int n, q, x;
int nums[100010];

int lowbit(int x) {
    return x & -x;
}

void add(int u, int x) {
    while (u <= n) {
        nums[u] += x;
        u += lowbit(u);
    }
}


int count(int u) {
    int res = 0;
    while (u) {
        res += nums[u];
        u -= lowbit(u);
    }
    return res;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) {
        cin >> x;
        add(i, x);
    }
    int op, a, b;
    while (q -- ) {
        cin >> op >> a >> b;
        if (op == 1) {
            add(a, b);
        } else {
            cout << count(b) - count(a - 1) << endl;
        }
    }
}