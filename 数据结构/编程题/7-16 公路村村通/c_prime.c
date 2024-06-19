#include <stdio.h>
#include <string.h>

#define INF 0x3f3f3f3f
#define N 1010

int n, m;           // n表示点数
int g[N][N];        // 邻接矩阵，存储所有边
int dist[N];        // 存储其他点到当前最小生成树的距离
int st[N];          // 存储每个点是否已经在生成树中

// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim() {
    // 将距离初始化为INF（0x3f3f3f3f），结果初始化为0
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    // 遍历每个顶点
    for (int i = 0; i < n; i ++ ) {
        int t = -1;
         // 找到距离最小且尚未在生成树中的顶点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 如果图不连通，返回INF
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];// 如果不是第一个顶点，则将距离添加到结果中
        // 将选定的顶点标记为生成树的一部分
        st[t] = 1;
        // 根据选定的顶点更新到其他顶点的距离
        for (int j = 1; j <= n; j ++ ) dist[j] = (dist[j] < g[t][j]) ? dist[j] : g[t][j];
    }
    return res;
}

int main() {
    // 读取输入的节点数和边数
    scanf("%d %d", &n, &m);

    // 读取边的信息
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = g[b][a] = w;
    }
    int res = prim();
    if (res > INF / 2) printf("-1");
    else printf("%d", res);

    return 0;
}
