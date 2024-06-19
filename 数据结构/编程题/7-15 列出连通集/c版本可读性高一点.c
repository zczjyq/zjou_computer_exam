#include <stdio.h>
#include <stdbool.h>

#define MAXN 110

int n, e;
bool bool_bfs[MAXN], bool_dfs[MAXN];
int f[120][120];

int q[MAXN], hh = 0, tt = -1;

// 初始化队列
void initQueue()
{
    hh = 0;
    tt = -1;
}

// 队列是否为空
bool isEmpty()
{
    return hh > tt;
}

// 入队
void enqueue(int item)
{
    q[++tt] = item;
}

// 出队
int dequeue()
{
    return q[hh++];
}

// 深度优先搜索 DFS 函数
void DFS(int u)
{
    bool_dfs[u] = true;
    printf("%d ", u); // 输出当前访问的节点
    for (int i = 0; i < n; i++)
        if (!bool_dfs[i] && f[u][i] == 1) // 如果当前节点未被访问过，并且与 u 联通
            DFS(i);
}

// 广度优先搜索 BFS 函数
void BFS(int u)
{
    initQueue();
    enqueue(u);
    bool_bfs[u] = true;
    while (!isEmpty())
    {
        int u = dequeue();
        printf("%d ", u); // 输出当前访问的节点
        for (int i = 0; i < n; i++)
            if (!bool_bfs[i] && f[u][i] == 1)
            { // 如果当前节点未被访问过，并且与 u 联通
                enqueue(i);
                bool_bfs[i] = true;
            }
    }
}

int main()
{
    // 读取数据
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        f[a][b] = f[b][a] = 1;
    }

    // 深度优先搜索
    for (int i = 0; i < n; i++)
        if (!bool_dfs[i])
        {
            printf("{ ");
            DFS(i);
            printf("}\n");
        }

    // 广度优先搜索
    for (int i = 0; i < n; i++)
        if (!bool_bfs[i])
        {
            printf("{ ");
            BFS(i);
            printf("}\n");
        }

    return 0;
}
