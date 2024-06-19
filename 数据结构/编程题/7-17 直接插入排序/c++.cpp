#include <iostream>
#include <algorithm>

using namespace std;

int f[110], n;
void output() {
    for (int i = 0; i < n; i ++ ) 
        if (i == n - 1) cout << f[i] << endl;
        else cout << f[i] << ' ';
}
int main() {
    // 注意题目为多组测试数据
    while (cin >> n) {
        // 读取数组元素
        for (int i = 0; i < n; i++) cin >> f[i];

        // 插入排序
        for (int i = 1; i < n; i++) {
            int u = f[i];

            // 在已排序的部分找到合适的位置插入
            for (int j = 0; j < i; j++) {
                if (f[j] > u) {
                    // 向右移动元素以腾出插入位置
                    for (int k = i; k > j; k--) 
                        f[k] = f[k - 1];

                    // 插入元素到正确位置
                    f[j] = u;
                    break;
                }
            }

            // 输出当前排序状态
            output();
        }
    }
}