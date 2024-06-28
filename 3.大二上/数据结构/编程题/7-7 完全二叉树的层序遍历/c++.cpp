#include <iostream>

using namespace std;

const int N = 35;

int nums[N], tree[N];
int n, now = 1;

// 递归构建二叉树
void build(int root){
    if(root > n) return;// 当前结点编号超过结点总数直接return
    // 左右根
    build(root * 2);// 递归构建左子树
    build(root * 2 + 1);// 递归构建右子树
    tree[root] = nums[now ++];// 将当前结点值赋给树的当前结点，同时更新数组索引
}

int main(){
    cin >> n;
    for (int i = 1;i <= n; i ++ ) cin >> nums[i];
    build(1);// 从根结点1开始构建二叉树
    // 格式化输出
    for (int i = 1;i <= n; i ++ ) {
        if (i != 1) cout << ' ';
        cout << tree[i];
    }
}