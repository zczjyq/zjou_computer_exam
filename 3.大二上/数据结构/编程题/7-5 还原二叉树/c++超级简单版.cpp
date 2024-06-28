// 本题最好在纸上先把代码的流程走一遍，理解起来会快很多
#include <iostream>

using namespace std;

// 递归函数，求二叉树的高度
int dfs(char *pre, char *in, int n) {
    if (n == 0) return 0; // 若没有结点，为空树

    // 找到根结点在中序遍历中的位置
    int i;
    for (i = 0; i < n; i++)
        if (in[i] == pre[0])
            break;

    // 递归计算左子树的深度
    int left = dfs(pre + 1, in, i);
    // 递归计算右子树的深度
    int right = dfs(pre + i + 1, in + i + 1, n - i - 1);

    // 返回左右子树深度的较大值中的较大值加上根结点，即为树的高度
    return max(left, right) + 1;
}

int main() {
    int n;
    cin >> n;
    char pre[n + 1], in[n + 1]; // 先序和中序遍历序列
    cin >> pre >> in;
    
    // 输出二叉树的高度
    cout << dfs(pre, in, n);
}