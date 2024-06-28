#include <iostream>
#include <queue>

using namespace std;

int n, e;
bool bool_bfs[110], bool_dfs[110];
int f[120][120];
queue<int> q;

// DFS深度优先遍历
/* DFS模板1
void DFS(int u) {
    flag[u] = true;
    for (int i = 0; i < n; i ++ )
        if (!flag[i] && f[u][i] == 1)
            DFS(i);
            ………………后续逻辑
}
 DFS模板2
void DFS(int u) {
    for (int i = 0; i < n; i ++ )
        if (!flag[i] && f[u][i] == 1) {
            flag[u] = true;
            DFS(i);
            ………………后续逻辑
            flag[u] = false;
        }
}
本题采用第一种方法
*/
void DFS(int u) {
    bool_dfs[u] = true;
    cout << u << ' '; // 输出当前访问的节点
    // 如果当前节点没有访问过，并且u i点联通
    for (int i = 0; i < n; i++)
        if (!bool_dfs[i] && f[u][i] == 1)
            DFS(i);
}

// BFS广度优先遍历
/* BFS模板1
flag 一定要在入队时操作 放在pop后面操作会出问题
void BFS(int u) {
    q.push(u);
    flag[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i ++ )
            if (!bool_bfs[i] && f[u][i] == 1) {
                q.push(i);
                flag[i] = true;
            }
    }
}
*/
void BFS(int u) {
    q.push(u);
    bool_bfs[u] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << ' '; // 输出当前访问的节点
        q.pop();
        for (int i = 0; i < n; i++)
            // 如果当前节点没有访问过，并且u i点联通
            if (!bool_bfs[i] && f[u][i] == 1)
            {
                q.push(i);
                bool_bfs[i] = true;
            }
    }
}

int main() {
    // 读数据
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        f[a][b] = f[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!bool_dfs[i]) {
            cout << "{ ";
            DFS(i);
            cout << "}\n";
        }

    for (int i = 0; i < n; i++)
        if (!bool_bfs[i]) {
            cout << "{ ";
            BFS(i);
            cout << "}\n";
        }
}