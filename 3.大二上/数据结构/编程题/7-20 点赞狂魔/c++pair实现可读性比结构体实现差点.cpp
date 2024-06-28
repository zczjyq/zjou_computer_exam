#include <iostream>
#include <unordered_map>
#include <algorithm>
#define x first
#define y second

using namespace std;
// 用二元组实现三元组 虽然c++有三元组tuple，但是pair用的习惯点
typedef pair<string, pair<int, double>> PSID;

int n, m, num;
PSID info[110];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        unordered_map<int, int> h;
        cin >> info[i].x;
        cin >> m;
        for (int j = 0; j < m; j ++ ) {
            cin >> num;
            // 用hash表判重
            if (h[num] == 0) info[i].y.x ++;
            h[num] = 1;
        }
        // 计算平均值
        info[i].y.y = (double)info[i].y.x / (double)m;
    }
    // 排序
    sort(info, info + n, [](PSID a, PSID b){
        if (a.y.x > b.y.x) return true;
        else if (a.y.x < b.y.x) return false;
        else return a.y.y > b.y.y;
    });
    // 格式化输出
    for (int i = 0; i < min(3, n); i ++ ) 
        if (i == 0) cout << info[i].x;
        else cout << ' ' << info[i].x;
    for (int i = n; i < 3; i ++ ) cout << " -";
}