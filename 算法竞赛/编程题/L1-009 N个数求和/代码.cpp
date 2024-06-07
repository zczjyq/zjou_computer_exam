#include <iostream>
#include <cstdio>

using namespace std;

// 定义一个求最大公约数的函数，使用递归方法
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n, fz_ans = 0, fm_ans = 1; // 初始化分子fz_ans为0，分母fm_ans为1，这是因为开始时没有任何分数相加
    scanf("%d", &n); // 输入分数的个数
    for (int i = 0; i < n; i++) {
        int fz, fm;
        scanf("%d/%d", &fz, &fm); // 输入每个分数的分子和分母
        fz_ans = fz_ans * fm + fz * fm_ans; // 交叉相乘并相加，处理分数的加法
        fm_ans = fm_ans * fm; // 分母相乘
        int num = gcd(fz_ans, fm_ans); // 计算当前结果的最大公约数以简化分数
        fz_ans /= num; // 简化分子
        fm_ans /= num; // 简化分母
    }
    if (fm_ans == 1) {
        printf("%d", fz_ans); // 如果分母为1，则只输出分子（整数）
    } else if (fz_ans > fm_ans) {
        printf("%d %d/%d", fz_ans / fm_ans, fz_ans % fm_ans, fm_ans); // 如果分子大于分母，输出带分数
    } else {
        printf("%d/%d", fz_ans, fm_ans); // 否则，输出真分数
    }
    return 0;
}
