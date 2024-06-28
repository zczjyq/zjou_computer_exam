// 本题用到 kruskal算法，但是由于数据量非常小使用prime算法也是一样的,但是正常来说应该是要用kruskal

#include <iostream>
#include <algorithm>

using namespace std;

// 定义边的结构体
struct Edge {
    int a, b, w;
}e[1010 * 3];

// 记录连通分量数量的变量
int cnt;
// 存储并查集的数组
int p[1010];
// 输入的节点数、边数和最终结果
int n, m, res;

// 并查集的查找函数
int find(int u) {
    // 如果根节点不是自己，说明是不一个独立的集合，递归查找根节点
    if (p[u] != u) u = find(p[u]);    
    return p[u]; // 不能写u在某些情况下return u会出问题，虽然本题没问题
}

int main() {
    // 读取输入的节点数和边数
    cin >> n >> m;
    
    // 初始化并查集
    for (int i = 0; i < n + 1; i++) p[i] = i;

    // 读取边的信息
    for (int i = 0; i < m; i++)
        cin >> e[i].a >> e[i].b >> e[i].w;

    // 按边的权值升序排序
    sort(e, e + m, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    // 遍历边，构建最小生成树
    for (int i = 0; i < m; i++) {
        // 查找两个节点所属的集合
        int a = find(e[i].a);
        int b = find(e[i].b);

        // 如果不在同一个集合中，则合并集合并计算总权值
        if (a != b) {
            res += e[i].w;
            p[a] = b; // 将两个点放到一个集合中
            cnt++;
        }
    }

    // 判断最终的连通分量数量是否符合要求，输出结果
    if (cnt < n - 1) cout << -1 << endl;
    else cout << res << endl;
}