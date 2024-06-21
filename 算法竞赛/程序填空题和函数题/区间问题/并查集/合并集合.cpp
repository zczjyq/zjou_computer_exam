// https://www.acwing.com/problem/content/description/838/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m, a, b;
int p[N];

// 并查集主要操作
int find(int u) {
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    while (m -- ) {
        string op;
        cin >> op >> a >> b;
        a = find(a), b = find(b);
        if (op == "M") 
            p[a] = b; 
        else 
            if (a == b) puts("Yes");
            else puts("No");
    }
}