#include <iostream>

using namespace std;

const int N = 25;
int n;
int mid[N], back[N];
int tree[N][N];

void build(int ml, int mr, int bl, int br, int deep) {
    if (ml > mr) return;
    int root = back[br], node = ml;
    // 找中序中的根节点
    while (root != mid[node]) node ++ ;
    tree[deep][++ tree[deep][0]] = root;
    build(ml, node - 1, bl, bl + node - ml - 1, deep + 1);
    build(node + 1, mr, bl + node - ml, br - 1, deep + 1);
}

int main() {
    cin >> n;
    // 读入
    for (int i = 1; i <= n; i ++ ) cin >> mid[i];
    for (int i = 1; i <= n; i ++ ) cin >> back[i];
    // 建树
    build(1, n, 1, n, 1);
    for (int i = 1; tree[i][0] != 0; i ++ ) {
        if (i == 1) cout << "R:";
        cout << " " << tree[i][tree[i][0]];
    }
    cout << endl;
    for (int i = 1; tree[i][0] != 0; i ++ ) {
        if (i == 1) cout << "L:";
        cout << " " << tree[i][1];
    }
}