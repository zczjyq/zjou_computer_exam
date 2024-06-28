#include <stdio.h>

int f[110], n;

void output() {
    for (int i = 0; i < n; i++)
        if (i == n - 1) printf("%d\n", f[i]);
        else printf("%d ", f[i]);
}

int main() {
    // 注意题目为多组测试数据
    while (scanf("%d", &n) != EOF) {
        // 读取数组元素
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);

        // 插入排序
        for (int i = 1; i < n; i++) {
            int u = f[i];

            // 在已排序的部分找到合适的位置插入
            int j;
            for (j = i - 1; j >= 0 && f[j] > u; j--) {
                // 向右移动元素以腾出插入位置
                f[j + 1] = f[j];
            }

            // 插入元素到正确位置
            f[j + 1] = u;

            // 输出当前排序状态
            output();
        }
    }

    return 0;
}
