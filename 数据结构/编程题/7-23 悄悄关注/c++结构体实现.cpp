// 注意本题数据量为1e4理论上来说使用N^2时间复杂度的排序不会超时，但是由于本题常数很大，会导致超时，如果手写排序，必须要用快排或者归并排序

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Info {
    string name;
    int likes;
};

int n, m;
unordered_map<string, int> h; // 哈希表
Info infos[10010];

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        h[name] = 1; // 将用户的关注列表中的人标记为1
    }

    int all = 0; // 点赞数初始化
    cin >> n;

    // 初始化数组元素
    for (int i = 0; i < n; i++) {
        cin >> infos[i].name >> infos[i].likes;
        all += infos[i].likes; // 累计点赞数
    }

    double avg = all / static_cast<double>(n); // 计算点赞平均数
    bool flag = true; // 用于标记是否存在未获奖且点赞数高于点赞平均数的名字
    sort(infos, infos + n, [](Info a, Info b) {
        return a.name < b.name; // 按姓名字典序排序选手信息
    });

    for (int i = 0; i < n; i++) {
        if (avg < infos[i].likes && h[infos[i].name] == 0) {
            cout << infos[i].name << endl; // 输出未出现但点赞数高于点赞平均数的姓名
            flag = false;
        }
    }

    if (flag) cout << "Bing Mei You" << endl; // 如果没有符合条件的人，则输出"Bing Mei You"
}
