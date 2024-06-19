// 注意本题数据量为1e4理论上来说使用N^2时间复杂度的排序不会超时，但是由于本题常数很大，会导致超时，如果手写排序，必须要用快排或者归并排序

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<string, int> PSI;

int n, m;
unordered_map<string, int> h; // 哈希表
PSI info[10010];

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        h[name] = 1; // 将用户的关注列表中的人标记为1
    }

    int all = 0; // 点赞数初始化
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> info[i].first >> info[i].second; // 输入姓名和点赞数
        all += info[i].second; // 累计点赞数
    }

    double avg = all / (double)n; // 计算点赞平均数
    bool flag = true; // 用于标记是否存在未获奖且点赞数高于点赞平均数的名字
    sort(info, info + n, [](PSI a, PSI b) {
        return a.first < b.first; // 按姓名字典序排序选手信息
    });

    for (int i = 0; i < n; i++) {
        if (avg < info[i].second && h[info[i].first] == 0) {
            cout << info[i].first << endl; // 输出未出现但点赞数高于点赞平均数的姓名
            flag = false;
        }
    }

    if (flag) cout << "Bing Mei You" << endl; // 如果没有符合条件的人，则输出"Bing Mei You"
}
