#include <iostream>
#include <queue>
using namespace std;

const int N = 25;

int n, cnt, inorder[N], postorder[N], deep;
int res[N][N];
queue <int> q;
struct node {
    int value, l = -1, r = -1;
}nodes[N];

int build(int inorder_l, int inorder_r, int postorder_l, int postorder_r) {
    if (inorder_l > inorder_r) return -1;  // 如果没有节点，则返回 -1
    // 获取后序遍历的最后一个节点，也将是根节点
    int root = postorder[postorder_r], idx = cnt ++ ;
    nodes[idx].value = root;
    int pos = inorder_l;
    // 获取中序遍历，根节点所在位置
    while (inorder[pos] != root) pos++;
    // 构建左子树
    nodes[idx].l = build(inorder_l, pos - 1, postorder_l, postorder_l + (pos - 1 - inorder_l));
    // 构建右子树
    nodes[idx].r = build(pos + 1, inorder_r, postorder_l + pos - inorder_l, postorder_r - 1);
    return idx;
}

int main() {
    // 输入
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> inorder[i];
    for (int i = 1; i <= n; i ++ ) cin >> postorder[i];
    // 建树
    build(1, n, 1, n);

    // 层序遍历
    q.push(0);
    while (!q.empty()) {
        // 根据当前这层的数量来循环
        for (int i = q.size(); i > 0; i -- ) {
            int j = q.front(); q.pop();
            // 每层的结果按照从左到右储存到res里面
            res[deep][ ++ res[deep][0]] = nodes[j].value;
            if (nodes[j].l != -1) q.push(nodes[j].l);
            if (nodes[j].r != -1) q.push(nodes[j].r);
        }
        // 加深深度
        deep ++ ;
    }
    // 格式化输出
    cout << "R:";
    for (int i = 0; i < deep; i ++ ) cout << ' ' << res[i][res[i][0]];
    cout << endl << "L:";
    
    for (int i = 0; i < deep; i ++ ) cout << ' ' << res[i][1];
    cout << endl;
}