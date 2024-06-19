// 有点算是投机取巧
#include <iostream>
#include <algorithm>

using namespace std;

int n, Max = 0; // n: 数组大小, Max: 数组中最大的数字
int f[1010];    // 存储输入的数组

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> f[i];
        Max = max(Max, f[i]); // 记录数组中的最大值
    }
    
    // 基数排序的实现
    for (int exp = 1 ; Max / exp > 0; exp *= 10 ) {
        // stable_sort() 也是一种O(n log n)时间复杂度的排序算法，但它保证稳定性，即相等的元素将保持其原始顺序
        stable_sort(f, f + n, [exp](int a, int b){
            return a / exp % 10 < b / exp % 10; // 按当前位数进行稳定排序
        });
        
        // 格式化输出当前排序结果
        for (int j = 0; j < n; j ++ ) cout << f[j] << ' ';
        cout << endl;
    }
}
