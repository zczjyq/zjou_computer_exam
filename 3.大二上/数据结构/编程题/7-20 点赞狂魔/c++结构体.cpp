#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 用结构体实现三元组
struct StudentInfo {
    string name;
    int count;
    double average;
};

int n, m, num;
StudentInfo info[110];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> h;
        cin >> info[i].name;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> num;
            // 用hash表判重
            if (h[num] == 0) info[i].count++;
            h[num] = 1;
        }
        // 计算平均值
        info[i].average = (double)info[i].count / (double)m;
    }
    
    // 排序
    sort(info, info + n, [](const StudentInfo& a, const StudentInfo& b) {
        if (a.count > b.count) return true;
        else if (a.count < b.count) return false;
        else return a.average > b.average;
    });
    
    // 格式化输出
    for (int i = 0; i < min(3, n); i++) {
        if (i == 0) cout << info[i].name;
        else cout << ' ' << info[i].name;
    }
    for (int i = n; i < 3; i++) cout << " -";
}
