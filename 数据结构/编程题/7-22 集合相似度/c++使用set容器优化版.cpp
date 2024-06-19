// 这题不用set容器太麻烦了，没实现
#include <iostream>
#include <set>

using namespace std;

int k, n, t;
int l, r, ans;

int main() {
    set<int> s[51];

    cin >> k;

    for (int i = 1; i <= k; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> t;
            s[i].insert(t);
        }
    }

    // 读取查询次数 t
    cin >> t;

    // 循环处理每次查询
    for (int i = 0; i < t; i++) {
        ans = 0;

        // 读取查询的两个集合编号 l 和 r
        cin >> l >> r;
        // 遍历集合 l 中的元素，检查其是否同时存在于集合 r 中
        // 老师写的使用迭代器，这边采用加强for循环会可读性和代码量都会优化不少
        for (int element : s[l]) ans += s[r].count(element);

        // 计算并输出相似度百分比
        printf("%.2f%%\n", ans * 100.0 / (s[r].size() + s[l].size() - ans));
    }
}
