// 一道很经典的贪心问题
#include <iostream>
#include <queue>

using namespace std;

int n, res;
priority_queue<int, vector<int>, greater<int>> q; // 优先队列 小根堆
// 嫌太麻烦的话，可以改成 priority_queue<int> q，在push的时候改成q.puah(x),//
// 取出的时候改成a = -q.top() 一样可以满足小根堆的性质
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (q.size() >= 2) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        res += a + b;
    }
    // res += q.top();
    cout << res;
}