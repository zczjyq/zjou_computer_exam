#include <iostream>
#include <queue>
using namespace std;
const int N = 25;
int n, cnt, inorder[N], postorder[N], deep;
int res[N][N];
queue <int> q;
struct node {
    int value, l = -1, r = -1;
}nodes[N];

int build(int inorder_l, int inorder_r, int postorder_l, int postorder_r) {
    if (inorder_l > inorder_r) return -1;
    int root = postorder[postorder_r], idx = cnt ++ ;
    nodes[idx].value = root;
    int pos = inorder_l;
    while (inorder[pos] != root) pos++;
    nodes[idx].l = build(inorder_l, pos - 1, postorder_l, postorder_l + (pos - 1 - inorder_l));
    nodes[idx].r = build(pos + 1, inorder_r, postorder_l + pos - inorder_l, postorder_r - 1);
    return idx;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> inorder[i];
    for (int i = 1; i <= n; i ++ ) cin >> postorder[i];

    build(1, n, 1, n);
    q.push(0);
    while (!q.empty()) {
        for (int i = q.size(); i > 0; i -- ) {
            int j = q.front(); q.pop();
            res[deep][ ++ res[deep][0]] = nodes[j].value;
            if (nodes[j].l != -1) q.push(nodes[j].l);
            if (nodes[j].r != -1) q.push(nodes[j].r);
        }
        deep ++ ;
    }
    cout << "R:";
    for (int i = 0; i < deep; i ++ ) cout << ' ' << res[i][res[i][0]];
    cout << endl << "L:";
    for (int i = 0; i < deep; i ++ ) cout << ' ' << res[i][1];
    cout << endl;
}