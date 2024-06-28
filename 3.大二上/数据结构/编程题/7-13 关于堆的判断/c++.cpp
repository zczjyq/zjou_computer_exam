// 本题难度不大，主要是细节上要注意

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
// 一定要将a[0]的值初始化为负无穷，因为题目会有负数不初始化为负无穷会出问题
int a[N] = {-0x3f3f3f3f}; // 初始化数组，用于存储堆的元素

// 查找元素在堆中的位置 PS 如果想进一步降低时间复杂度，可以将这步换成哈希表索引去查找
int f(int x) {
    for (int i = 1; i <= n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int main() {
    cin >> n >> m; // 输入堆的大小和操作次数
    cin >> a[1];   // 输入堆的第一个元素（根节点）注意下标从1开始

    // 构建堆
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        // a[k / 2]是a[k]的父节点
        for (int k = i; a[k] < a[k / 2]; k /= 2) {
            swap(a[k], a[k / 2]); // 调整堆的结构，保持堆的性质
        }
    }

// ————————————————————————————————————————————————————————————————————————
// 下面为判断操作
    while (m--) {
        int x1, b;
        string op;
        cin >> x1 >> op; // 读取操作数和操作类型

        if (op == "is") {
            cin >> op >> op; // 读取"is"后的字符串
            if (op == "root") {
                // 判断是否为"is root"操作，输出相应的结果
                if (a[1] == x1) cout << "T" << endl;
                else cout << "F" << endl;
            } else if (op == "parent") {
                cin >> op >> b; // 读取"parent"后的字符串和操作数
                // 判断是否为"is parent of"操作，输出相应的结果
                if (f(x1) == f(b) >> 1 && f(x1) != -1 && f(b) != -1) 
                    cout << "T" << endl;
                else cout << "F" << endl;
            } else if (op == "child") {
                cin >> op >> b; // 读取"child"后的字符串和操作数
                // 判断是否为"is child of"操作，输出相应的结果
                if (f(b) == f(x1) >> 1 && f(x1) != -1 && f(b) != -1)
                    cout << "T" << endl;
                else cout << "F" << endl;
            }
        } else {
            cin >> b >> op >> op; // 读取其他操作的字符串和操作数
            // 判断是否为"is ancestor of"或"is descendant of"操作，输出相应的结果
            if (f(b) / 2 == f(x1) / 2 && f(x1) != -1 && f(b) != -1)
                cout << "T" << endl;
            else cout << "F" << endl;
        }
    }
}
