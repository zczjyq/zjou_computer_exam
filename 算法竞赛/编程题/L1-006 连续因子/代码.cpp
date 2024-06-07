#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;            // 要检查的数字
    int start = 0; // 最长序列的起始数字
    int maxLen = 0;   // 最长序列的长度
    int len;   // 当前序列的长度
    int current;      // 当前的除数
    int modifiedN;    // 被修改后用于计算的n

    cin >> n;
    // 遍历所有可能的起始数字,这边只能用sqrt 或者 i < n / i, 用i * i < n 会超时
    for (int i = 2; i < sqrt(n); i++) {
        len = 0;
        current = i;
        modifiedN = n;
        // 检查从i开始的连续整数是否能整除modifiedN
        while (modifiedN % current == 0) {
            len++;
            modifiedN /= current;
            current++;
        }
        // 更新找到的最长序列
        if (len > maxLen) {
            maxLen = len;
            start = i;
        }
    }
    // 如果没有找到任何可以整除n的连续整数序列
    if (start == 0) {
        start = n; // 序列就是n本身
        maxLen = 1;   // 长度为1
    }
    // 输出最长序列的长度
    cout << maxLen << endl;
    // 输出序列本身
    for (int i = start, count = 1; count <= maxLen; i++, count++) {
        if (count > 1) cout << "*";
        cout << i;
    }
}
