#include <stdio.h>

#define N 35

int nums[N], tree[N];
int now = 1, n;

// 递归构建二叉树
void build(int root) {
    if (root > n) return; // 当前结点编号超过结点总数，返回
    build(root * 2);         // 递归构建左子树
    build(root * 2 + 1);     // 递归构建右子树
    tree[root] = nums[now++]; // 将当前结点值赋给树的当前结点，同时更新数组索引
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i]);

    build(1); // 从根结点1开始构建二叉树

    // 输出构建好的二叉树的结点值
    for (int i = 1; i <= n; i++) {
        if (i == n) printf("%d\n", tree[i]);
        else printf("%d ", tree[i]);
    }

    return 0;
}
