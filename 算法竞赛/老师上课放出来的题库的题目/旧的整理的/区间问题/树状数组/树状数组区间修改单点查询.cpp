#include <iostream>

using namespace std;

int n, m;
int nums[100010], tr[100010];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int u) {
    while (x <= n) {
        tr[x] += u;
        x += lowbit(x);
    }
}

int count(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> nums[i];
    for (int i = 1; i <= n; i ++ ) add(i, nums[i] - nums[i - 1]);
    while (m -- ) {
        string op;
        int a, b, c;
        cin >> op;
        if (op == "Q") {
            cin >> a;
            cout << count(a) << endl;
        } else {
            cin >> a >> b >> c;
            add(a, c);
            add(b + 1, -c);
        }
    }
}