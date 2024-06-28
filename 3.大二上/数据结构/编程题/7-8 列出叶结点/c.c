// 本题要求按从上到下、从左到右的顺序输出其所有叶结点。
// 所以必须采用广度优先遍历，且先将左孩子入队

#include <stdio.h>
#include <string.h>

// 结点的定义
struct TreeNode {
    int l;
    int r;
};

int main() {
    // 输入结点数
    int n;
    scanf("%d", &n);

    // 定义结点数组和标记数组
    struct TreeNode node[15];
    int st[15] = {0}; // 0表示未被使用
    int flag = 0;     // 输出格式标记
    int q[15];
    int front = 0, rear = 0; // 队列的头尾指针

    // 输入结点信息
    for (int i = 0; i < n; i++) {
        char l, r;
        scanf(" %c %c", &l, &r);
        node[i].l = l - '0';
        node[i].r = r - '0';
        if (node[i].l >= 0) st[node[i].l] = 1; // 结点已被使用
        if (node[i].r >= 0) st[node[i].r] = 1; // 结点已被使用
    }

    int u = 0;
    // 找到根结点
    for (int i = 0; i < n; i++)
        if (!st[i])
            u = i;

    q[rear++] = u;
    // 广度优先搜索
    while (front < rear) {
        u = q[front++];
        if (node[u].l >= 0) q[rear++] = node[u].l;
        if (node[u].r >= 0) q[rear++] = node[u].r;
        if (node[u].l < 0 && node[u].r < 0) {
            // 输出叶子结点
            if (flag) printf(" %d", u);
            else printf("%d", u);
            flag = 1; // 设置输出格式标记
        }
    }
    printf("\n");

    return 0;
}
