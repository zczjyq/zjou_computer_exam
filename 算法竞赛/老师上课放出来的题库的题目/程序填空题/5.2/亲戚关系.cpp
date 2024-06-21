// https://www.acwing.com/problem/content/description/1251/
// 这题不一定，但是题型不会有什么太大区别

#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int p[N];
// 并查集
int find(int u) {
    if (u != p[u]) p[u] = find(p[u]);
    return p[u];
}
int q, n, m, a, b;

int main() {
    cin >> n >> m;
    // 并查集初始化
    for (int i = 0; i <= n; i ++ ) p[i] = i;
    for (int i = 0; i < m; i ++ ) {
        scanf("%d %d", &a, &b);
        a = find(a), b = find(b);
        p[a] = b;
    }
    cin >> q;
    while (q -- ) {
        scanf("%d %d", &a, &b);
        if (find(a) == find(b)) printf("Yes\n");
        else printf("No\n");
    }
}