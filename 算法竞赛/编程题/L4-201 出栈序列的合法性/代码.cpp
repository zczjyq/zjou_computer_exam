#include <iostream>

using namespace std;

int m, n, k; // 定义全局变量m, n, k，分别表示栈的最大容量，序列长度和测试用例数量

// 检查函数，用来检验是否能通过栈操作得到特定的输出序列
void check() {
    int hh = -1; // 栈顶指针（栈顶元素的索引）
    int cnt = 1; // 下一个将要推入栈的数字
    int s[1010]; // 用于存储数字的栈
    int nums[1010]; // 用来存储输入序列的数组

    // 输入序列的数字
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 处理输入序列中的每个数字
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        // 如果栈为空或当前数字大于等于计数器
        if (hh == -1 || x >= cnt) {
            // 将数字推入栈，直到达到当前数字
            while (x >= cnt) {
                s[++hh] = cnt++;
            }
            // 检查栈大小是否超过最大允许大小
            if (hh + 1 > m) {
                puts("NO");
                return;
            }
        } else if (s[hh] != x) { // 如果栈顶数字与当前数字不匹配
            puts("NO");
            return;
        }
        // 从栈中弹出顶部元素
        hh--;
    }
    // 如果所有数字都按规则处理完毕，输出"YES"
    puts("YES");
}

int main() {
    // 读入m, n, k的值
    cin >> m >> n >> k;
   
