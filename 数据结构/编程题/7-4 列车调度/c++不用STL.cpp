#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int rail[N];
int top = 0;
void put(int num) {
    int l, r, m;
    // 当top=0或输入的列车序号比每个轨道最后一趟列车序号还大时，开辟新轨道
    if (!top || rail[top - 1] < num) rail[top++] = num;
    else {
        l = 0;
        r = top - 1;
        // 二分查找
        while (l <= r) {
            m = (l + r) / 2;
            if (rail[m] < num) l = m + 1;
            else r = m - 1;
        }
        rail[m] = num; // 将序号为num的列车放入相应轨道
    }
}
int main() {
    int i, N, num;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> num;
        put(num);
    }
    cout << top;
}
