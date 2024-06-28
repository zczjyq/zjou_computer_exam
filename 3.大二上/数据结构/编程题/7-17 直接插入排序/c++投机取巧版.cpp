#include <iostream>
#include <algorithm>

using namespace std;

int f[110], n;
// 输出
void output() {
    for (int i = 0; i < n; i ++ ) 
        // 格式化输出
        if (i == n - 1) cout << f[i] << endl;
        else cout << f[i] << ' ';
}
int main() {
    // 注意题目为多组测试数据
    while (cin >> n) {
        for (int i = 0; i < n; i ++ ) cin >> f[i];
        // 由插入排序的性质可得，每次插入都是保证前i + 1项有序，所以本题直接调用sort函数对i+1项排序
        for (int i = 1; i < n; i ++ ) {
            sort(f, f + i + 1);
            output();
        }
    }
}