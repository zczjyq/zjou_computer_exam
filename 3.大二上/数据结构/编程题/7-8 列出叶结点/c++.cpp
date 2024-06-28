// 本题要求按从上到下、从左到右的顺序输出其所有叶结点。
// 所以必须采用广度优先遍历，且先将左孩子入队

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 定义结构体表示二叉树节点
struct {
    int left;  // 左孩子
    int right;  // 右孩子
} node[15];

int n;  // 二叉树节点个数
bool st[15], flag;  // 数组st用于寻找根节点，flag用于标记输出格式
queue<int> q;  // 定义队列用于层序遍历

int main() {
    // 输入二叉树节点个数
    cin >> n;

    // 输入每个节点的左右孩子，并更新st数组标记已经存在的节点
    for (int i = 0; i < n; i++) {
        char left, right;
        cin >> left >> right;
        node[i].left = left - '0', node[i].right = right - '0';
        if (node[i].left >= 0) st[node[i].left] = true;
        if (node[i].right >= 0) st[node[i].right] = true;
    }

    int u = 0;

    // 寻找根节点，即未被标记的节点
    for (int i = 0; i < n; i++)
        if (!st[i])
            u = i;

    // 从根节点开始层序遍历二叉树
    // 广度优先遍历
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();

        // 将左右孩子入队
        // 注意顺序
        if (node[u].left >= 0) q.push(node[u].left);
        if (node[u].right >= 0) q.push(node[u].right);

        // 判断是否为叶子节点，如果是则输出节点的值
        if (node[u].left < 0 && node[u].right < 0) {
            if (flag) cout << ' ' << u;
            else cout << u;
            flag = true;
        }
    }
    cout << endl;
}
